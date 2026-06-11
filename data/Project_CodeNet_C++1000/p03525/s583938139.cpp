#include <bits/stdc++.h>
#include <stdio.h>
#include <math.h>
using namespace std;
using vi = vector<int>;
using vll = vector<long long int>;
using vb = vector<bool>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<long long int>>;
using ll = long long int;

class Radix {
private:
  const char* s;
  int a[128];
public:
  Radix(const char* s = "0123456789ABCDEF") : s(s) {
    int i;
    for(i = 0; s[i]; ++i)
      a[(int)s[i]] = i;
  }
  std::string to(long long p, int q) {
    int i;
    if(!p)
      return "0";
    char t[64] = { };
    for(i = 62; p; --i) {
      t[i] = s[p % q];
      p /= q;
    }
    return std::string(t + i + 1);
  }
  std::string to(const std::string& t, int p, int q) {
    return to(to(t, p), q);
  }
  long long to(const std::string& t, int p) {
    int i;
    long long sm = a[(int)t[0]];
    for(i = 1; i < (int)t.length(); ++i)
      sm = sm * p + a[(int)t[i]];
    return sm;
  }
};

int main(){
    ll N; cin >> N;
    vll d(N+1);
    d[0] = 0;
    for(int i=1; i<N+1; i++){
        cin >> d[i];
    }
    if(N + 1 > 24){
        cout << 0;
    }else if(N + 1 == 24){
        vll p(13, 0);
        for(int i=1; i<N+1; i++){
            p[d[i]]++;
        }
        bool m = true;
        for(int i=1; i<12; i++){
            if(p[i] != 2){
                m = false;
            }
        }
        if(m){
            if(p[12] != 1){
                m = false;
            }
        }
        if(m){cout << 1;}
        else{cout << 0;}
    }else{
        ll mini = 0;
        for(int i=0; i<pow(2,N); i++){
            Radix r;
            string s = r.to(i, 2);
            if(s.size() < N){
                ll m = N - s.size();
                string p = "";
                for(int i=0; i<m; i++){
                    p += '0';
                }
                s = p + s;
            }
            vll D(N+1); D[0] = 0;
            for(int j=1; j<N+1; j++){
                if(s[j-1] == '0'){
                    D[j] = d[j];
                }else{
                    D[j] = 24 - d[j];
                }
            }
            ll mi = 10000;
            for(int j=0; j<N+1; j++){
                for(int k=j+1; k<N+1; k++){
                    ll g = min(abs(D[j] - D[k]), 24-abs(D[j] - D[k]));
                    if(g < mi){
                        mi = g;
                    }
                }
            }
            if(mi > mini){
                mini = mi;
            }
        }
        cout << mini;
    }
}
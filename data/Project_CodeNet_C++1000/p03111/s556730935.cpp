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
    ll N, A, B, C; cin >> N >> A >> B >> C ;
    vll l(N);
    for(int i=0; i<N; i++){
        cin >> l[i];
    }
    ll min = 10000000000000;
    for(int i=0; i<pow(4,N); i++){
        vll a(0), b(0), c(0), d(0);
        Radix r;
        string k = r.to(i, 4);
        if(k.size() == N){
            for(int j=0; j<N; j++){
                if(k[j] == '0'){
                    a.emplace_back(l[j]);
                }else if(k[j] == '1'){
                    b.emplace_back(l[j]);
                }else if(k[j] == '2'){
                    c.emplace_back(l[j]);
                }else{
                    d.emplace_back(l[j]);
                }
            }
        }else{
            int p = k.size();
            string m = "";
            for(int j=0; j<N-p; j++){
                m.push_back('0');
            }
            string h = m + k;
            for(int j=0; j<N; j++){
                if(h[j] == '0'){
                    a.emplace_back(l[j]);
                }else if(h[j] == '1'){
                    b.emplace_back(l[j]);
                }else if(h[j] == '2'){
                    c.emplace_back(l[j]);
                }else{
                    d.emplace_back(l[j]);
                }
            }
        }
        ll res = 0;
        ll s=0, t=0, u=0, v=0;
        for(auto x: a){s+=x;}
        for(auto x: b){t+=x;}
        for(auto x: c){u+=x;}
        for(auto x: d){v+=x;}
        if(s==0||t==0||u==0){
            continue;
        }
        res += abs(A-s);
        res += abs(B-t);
        res += abs(C-u);
        res += (a.size()-1)*10;
        res += (b.size()-1)*10;
        res += (c.size()-1)*10;
        
        if(res < min){min = res;}
    }
    cout << min;
}
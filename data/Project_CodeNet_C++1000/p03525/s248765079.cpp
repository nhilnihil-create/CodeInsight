#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define VIEW(x) do {cerr << #x << ": "; for(auto i : x) cerr << i << " "; cerr << endl;} while(0)
#define ALL(x) (x).begin(),(x).end()
template<class T>bool umax(T &a, const T &b) {if(a<b){a=b;return 1;}return 0;}
template<class T>bool umin(T &a, const T &b) {if(b<a){a=b;return 1;}return 0;}

template<typename A,size_t N,typename T> void FILL(A (&array)[N],const T &val){fill((T*)array,(T*)(array+N),val);}
template<typename T> void FILL(vector<T> &v, const T &x) {fill(v.begin(), v.end(), x);}
template<typename T> void FILL(vector<vector<T>> &v, const T &x) {for(auto &i:v)fill(i.begin(), i.end(), x);}


int main() {
  int n; cin >> n;
  vector<int> d(13);
  d[0]++;
  rep(i,n) {
    int x; cin >> x;
    ++d[x];
  }
  int ans = 0;

  rep(i,13) if(d[i]>2) { puts("0"); return 0;}

  for (int bit = 0; bit < (1<<13); ++bit) {
    vector<int> v1;
    for (int i = 0; i < 13; ++i) {
      if(d[i] == 0) continue;
      if(d[i] > 1) {
        v1.push_back(i);
        v1.push_back(24 - i);
        continue;
      }
      if (bit & (1<<i)) v1.push_back(i);
      else v1.push_back(24 - i);
    }
    int nn = v1.size();
    int s = 100;
    rep(i, nn) rep(j, i+1, nn) {
      int x = abs(v1[i] - v1[j]);
      umin(s, min(x, 24-x));
    }
    umax(ans, s);
  }

  cout << ans << endl;
}

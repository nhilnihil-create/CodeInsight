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

struct CumulativeSum {
  vector<long long> csum;
  template<typename T>
  CumulativeSum(vector<T> const &input) : csum(input.size() + 1, 0) {
    for(int i = 0; i < (int)input.size(); i++) csum[i+1] = csum[i] + input[i];
  }
  long long query(int l, int r) { /* 0-indexed, inclusive */ return csum[r+1] - csum[l]; }
};


int main() {
  int n, k; cin >> n >> k;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  CumulativeSum cs(a);
  vector<ll> s;
  rep(l,n) rep(r,l,n) s.push_back(cs.query(l,r));

  ll mask = 0;
  for(int i=62; i>=0; --i) {
    ll bit = (1LL<<i);
    int count = 0;
    ll mb = mask + bit;
    for(auto x : s) if((mb & x) == mb) ++count;
    if(count >= k) mask += bit;
  }
  cout << mask << endl;
}

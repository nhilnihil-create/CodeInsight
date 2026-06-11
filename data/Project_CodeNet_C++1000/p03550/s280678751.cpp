#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i,a,b) for(int i=(a);i<(b);++i)

template<class T> inline void chmin(T& a, T b) {if (a > b) a = b;}
template<class T> inline void chmax(T& a, T b) {if (a < b) a = b;}

//vector出力
template <class T>ostream &operator<<(ostream &o,const vector<T>&v){
  o<<"{";
  for(int i=0;i<(int)v.size();i++) o << (i>0?", ":"") << v[i];
  o<<"}";
  return o;
}



int main() {
  int n,z,w;
  cin >> n >> z >> w;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  reverse(a.begin(),a.end());
  if (n>1)
  {if (abs(a[1]-a[0])<(abs(a[0]-w))) cout << abs(a[0]-w) << endl;
  else cout << abs(a[1]-a[0]) << endl;}
  else
  {
    cout << abs(a[0]-w) << endl;
  }
  
}
#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep2(i, l, r) for (ll i = (l); i < (r); i++)
#define ALL(x) (x).begin(), (x).end()     //昇順
#define RALL(x) (x).rbegin(), (x).rend()  // 降順
#define pri(x) cout << (x) << "\n"
#define pri2(x, y) cout << (x) << " " << (y) << "\n"
#define pri3(x, y, z) cout << (x) << " " << (y) << " " << (z) << "\n"
const long long mod = 1e9 + 7;
typedef long long ll;
typedef priority_queue<int> PQ;
typedef vector<long long> VL; // VL a(n);
typedef vector<bool> VB;
typedef vector<double> VD;
typedef vector<string> VS;
typedef vector<char> VC;
typedef vector<VS> VSS;
typedef vector<VC> VCC;
typedef vector<VL> VLL; // VII a(n,VI(m)) n * m
typedef pair<ll, ll> PL;
typedef map<ll, ll> MP; // MP a;
typedef vector<pair<ll, ll>> PS; // PS a(n);

template <class T, class U>
bool chmax(T &a, U b) {
  if (a <= b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T, class U>
bool chmin(T &a, U b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <typename T>
ostream &operator<<(ostream &os, vector<T> &v) {
  os << "{";
  rep(i, (int)v.size()) { os << v[i] << (i < v.size() - 1 ? ", " : ""); }
  os << "}";
  return os;
}

// g++ -std=c++11 prac.cpp
// operator << (cout,a);
// chmin(min,a)
ll sum(ll n){return n*(n+1)/2;} 

int main() {
  ll n,k,m,x=0,y=0,z=0,cnt=0,h=0,w=0,sum=0,ans=0,Max=0, Min=3e9+1;
  string s,t;
  cin >> n;
  VL a(n+2);
  a[0]=0;
  rep2(i,1,n+1) cin >> a[i];
  a[n+1]=0;
  rep(i,n+1){
    sum += abs(a[i]-a[i+1]);
  }
  for(int i=1; i<n+1; i++){
    pri(sum + abs(a[i-1]-a[i+1]) - abs(a[i-1]-a[i]) - abs(a[i]-a[i+1]));
  }
  return 0;
}
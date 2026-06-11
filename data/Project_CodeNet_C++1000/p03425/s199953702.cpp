#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rep2(i, l, r) for (int i = (l); i < (r); i++)
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

int main() {
  ll n,k,m,x=0,y=0,z = 0,cnt=0,h=0,w=0,ans=0,sum = 0, Max = -1, Min = 3e9+1;
  string s;
  cin >> n;
  VS a(n);
  VL b(5);
  rep(i,n) {
    cin >> a[i];
    if(a[i][0] == 'M'){ b[0]++; }
    if(a[i][0] == 'A'){ b[1]++; }
    if(a[i][0] == 'R'){ b[2]++; }
    if(a[i][0] == 'C'){ b[3]++; }
    if(a[i][0] == 'H'){ b[4]++; }
  }
  rep(i,3){
    for(int j=i+1; j<4;j++){
      for(int k=j+1; k<5; k++){
        ans += b[i]*b[j]*b[k];
      }
    }
  }
  pri(ans);
  return 0;
}
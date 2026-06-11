#include<bits/stdc++.h>
#define rep(i,n)  for(ll i = 0; i < n; i++)
#define vi vector<int>
#define all(x) (x).begin(),(x).end()
#define INF 1e9
using ll = long long;
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(b<a) { a=b; return 1; } return 0; }

int main(){
  int n; cin >> n;
  vi x(n); rep(i,n) cin >> x[i];
  vi tmp(n);
  tmp = x;
  sort(all(tmp));
  rep(i,n) cout << (x[i] <= tmp[n/2-1] ? tmp[n/2] : tmp[n/2-1]) << "\n";
  cout << "\n";
  return 0;
}

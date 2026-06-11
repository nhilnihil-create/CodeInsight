#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
#define vi vector<int>
#define all(x) (x).begin(),(x).end()
#define INF (1<<30)-1
using ll = long long;
using namespace std;
template<class T> inline bool chmax(T &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n,m; cin >> n >> m;
  string s,t; cin >> s >> t;
  for(int i = 0; i < __gcd(n,m); i++){
    if(s[i*(n/__gcd(n,m))] != t[i*(m/__gcd(n,m))]){
      cout << -1;
      return 0;
    }
  }
  cout << n*(m/__gcd(n,m));
  cout << "\n";
  return 0;
}

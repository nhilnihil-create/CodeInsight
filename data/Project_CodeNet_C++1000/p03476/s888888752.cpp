#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < int(n); i++)
#define vi vector<int>
#define all(x) (x).begin(),(x).end()
#define INF (1<<30)-1
using ll = long long;
using namespace std;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }

inline int isPrime(ll n){
  for(ll i = 2; i*i <= n; i++) if(n % i == 0) return 0;
  return 1;
}

int main(){
  cin.tie(0), ios::sync_with_stdio(false);
  int q; cin >> q;
  vi ans(101010);
  rep(i,101010){
    if(i%2 == 1) ans[i] += (isPrime(i)+isPrime((i+1)/2))/2;
    ans[i+1] += ans[i];
  }
  rep(i,q){
    int l,r; cin >> l >> r;
    cout << ans[r]-ans[max(l-1,1)] << endl;
  }
  cout << "\n";
  return 0;
}

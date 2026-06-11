#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define ll long long
#define rep(i,n) for(int i = 0; i < int(n); i++)
#define vi vector<int>
using namespace std;
const int INF = 1001001001;
const int MOD = 1e9+7;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T &a, const T &b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b){ if(b<a){ a=b; return 1; } return 0; }

int main(){
  cin.tie(0), ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<ll> a(n); rep(i,n) cin >> a[i];
  ll mx = 2, mn = 2;
  for(int i = n-1; 0 <= i; i--){
    mx = (mx/a[i])*a[i]+a[i]-1;
    mn = (mn+a[i]-1)/a[i]*a[i];
  }
  if(mn <= mx){
    cout << mn << " " << mx;
  }else{
    cout << -1;
  }
  cout << endl;
  return 0;
}

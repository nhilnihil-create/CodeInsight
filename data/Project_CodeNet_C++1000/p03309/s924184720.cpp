#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i<n;i++)
#define erep(i,n) for(int i = 0;i<=n;i++)
#define rep1(i,n) for(int i = 1;i<n;i++)
typedef long long ll;
#define vint vector<int>
#define vstring vector<string>
#define vll vector<ll>
#define vbool vector<bool>
#define INF 100000000

ll gcm(ll a,ll b);

int main(){
  int n;
  cin >> n;
  vint A(n);
  rep(i,n) cin >> A[i];
  vint dist(n);
  rep(i,n) dist[i] = A[i]-(i+1);
  sort(dist.begin(),dist.end());
  ll judge = dist[n/2];
  ll ans = 0;
  rep(i,n) ans += (ll)abs((dist[i] - judge));
  cout << ans << endl;
}





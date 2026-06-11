#include<bits/stdc++.h>
#define INF 1e9
#define llINF 1e18
#define MOD 1000000007
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long
#define vi vector<ll>
#define vvi vector<vi>
#define BITLE(n) (1LL<<((ll)n))
#define SHIFT_LEFT(n) (1LL<<((ll)n))
#define SUBS(s,f,t) ((s).substr((f),(t)-(f)))
#define ALL(a) (a).begin(),(a).end()
using namespace std;
ll rui[111111][30];
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n;cin>>n;
  string s;cin>>s;
  for(int i=0;i<n;i++){
    for(int j=0;j<26;j++)
      if(s[i]-'a' == j)rui[i+1][j] += rui[i][j]+1;
      else rui[i+1][j] += rui[i][j];
  }
  ll ans = 0;
  for(int i=0;i<n;i++){
    ll kosuu = 1;
    for(int j=0;j<26;j++){
      if(j == s[i]-'a')continue;
      kosuu *= (1+rui[n][j]-rui[i][j]);
      kosuu %=MOD;
    }
    ans += kosuu;
    ans %= MOD;
  }
  cout<<ans<<endl;
  return 0;
}

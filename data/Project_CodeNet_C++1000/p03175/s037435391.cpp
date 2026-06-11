                    //S.G.N.//
#include <bits/stdc++.h>
using namespace std;
typedef vector< long long > vi;
typedef long long ll;
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define endl "\n"
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define fr(n) for(ll i=0;i<n;i++)
#define tr(a) for(auto it=a.begin();it!=a.end();it++)
#define N 998244353445 
#define PI 3.1415926535897932384
#define F first
#define S second
#define mp make_pair
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod 1000000007
vector<ll> v[100001];
ll vis[100001]={0};
pair<ll,ll> dfs(ll i)
{
  vis[i]=1;
  vector<pair<ll,ll>> vect;
  tr(v[i])
  {
    if(vis[*it]==0)
    {
      vect.pb(dfs(*it));
    }
  }
  if(vect.size()==0)
    return (make_pair(1,1));
  else if(vect.size()==1)
  {
    return (make_pair((vect[0].first+vect[0].second)%mod,vect[0].first));
  }
  ll pro1=1;
  ll pro2=1;
  tr(vect)
  {
    pro1=(pro1*((it->first+it->second)%mod))%mod;
    pro2=(pro2*(it->first))%mod;
  }
  return (make_pair(pro1,pro2));
}
void solve()
{
 ll n;
 cin>>n;
 fr(n-1)
 {
 ll x,y;
 cin>>x>>y;
 v[x].pb(y);
 v[y].pb(x);
 }
 pair<ll,ll> p=dfs(1);
 cout<<(p.first+p.second)%mod;
}
int main()
{
  
  #ifndef ONLINE_JUDGE
     * freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
  #endif
  FAST
  ll test;
test=1;
  //cin>>test;
  while(test--)
  {
    solve();
  }
  return 0;
}

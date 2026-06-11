#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sf(n) scanf("%lld",&n)
#define sff(n,m) scanf("%lld %lld",&n,&m)
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define PLL pair<ll,ll>
#define mod 1000007
#define mx 100005
#define FILE freopen("input.txt","r",stdin)

ll P[mx];
ll ar[mx];

ll F(ll x)
{
  if(x==P[x]) return x;
  return P[x] = F(P[x]);
}

vector<PLL>v;

int main()
{
ll n,m;
sff(n,m);

for(ll i = 1;i<=n;i++){
  P[i] = i;
  ar[i] = 1;
}

while(m--)
{
  ll a,b;
  sff(a,b);

  v.push_back({a,b});
}

ll tot = (n*(n-1))/2;
ll ans = 0;
stack<ll>st;

for(ll i = v.size()-1;i>=0;i--){

    st.push(tot-ans);

    if(F(v[i].first)!=F(v[i].second)){
        ll px = F(v[i].first);
        ll py = F(v[i].second);
        ans+=(ar[px]*ar[py]);
        ar[px]+=ar[py];
        P[py] = px;
    }


}

while(!st.empty()){
    cout<<st.top()<<endl;
    st.pop();
}

return 0;
}

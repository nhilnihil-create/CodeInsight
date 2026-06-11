#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define ld long double
#define F first
#define S second
#define pii pair<ll,ll>

using namespace :: std;

const ll maxn=1e5+1050;
const ll mod=1e9+7;
const ll inf=1e9+5;

vector<pii> yal;
ll sz[maxn];
pii d[maxn];

int main(){
   ll n;
   cin>>n;
   ll sum=0;
   for(ll i=0;i<n;i++){
        cin>>d[i].F;
        sum+=d[i].F;
        d[i].S=i+1;
   }
   sort(d,d+n);
   fill(sz,sz+maxn,1);
   for(ll i=n-1;i>=1;i--){
        ll v=d[i].S;
        ll dpar=d[i].F+2*sz[v]-n;
        ll K=lower_bound(d,d+n,mp(dpar,0LL))-d;
        if(d[K].F!=dpar || dpar>=d[i].F || K>=n){
            cout<<-1;
            return 0;
        }
        ll par=d[K].S;
        sum-=2*sz[v]*(n-sz[v]);
        sz[par]+=sz[v];
        yal.pb(mp(min(v,par),max(v,par)));
   }
   if(sum!=0){
        cout<<-1;
        return 0;
   }
   sort(yal.begin(),yal.end());
   for(auto v:yal){
        cout<<v.F<<' '<<v.S<<endl;
   }
}

#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;
vector<pair<ll,ll> > v[200000];
bool maki[200000];
ll d[200000];
void dfs(int x){
    ll niko=v[x].size();
    for(int i=0;i<niko;i++){
        if(!maki[v[x][i].first]){
            maki[v[x][i].first]=true;
            d[v[x][i].first]=d[x]+v[x][i].second;
            dfs(v[x][i].first);
        }
    }
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    memset(maki,0,sizeof(maki));
    memset(d,0,sizeof(d));
    ll n,m;
    cin>>n>>m;
    ll l[m],r[m],dis[m];
    for(int i=0;i<m;i++){
        cin>>l[i]>>r[i]>>dis[i];
        l[i]--;r[i]--;
        v[l[i]].pb(make_pair(r[i],dis[i]));
        v[r[i]].pb(make_pair(l[i],-dis[i]));
    }
    for(int i=0;i<n;i++){
        if(!maki[i]){
            maki[i]=true;
            dfs(i);
        }
    }
    bool ans=true;
    for(int i=0;i<m;i++){
        if(d[r[i]]-d[l[i]]!=dis[i]){
            ans=false;
        }
    }
    cout << ((ans)?"Yes":"No")<<endl;
    return 0;
}
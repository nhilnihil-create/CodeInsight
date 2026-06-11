#include<bits/stdc++.h>
#define ll int
#define inf 999999999999
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define read(x)  freopen("input.txt","r",stdin);
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pi 2*acos(0.0)
#define ee exp(1)
#define mx 100000+9
using namespace std;
vector<pair<ll,ll> >v[mx];
ll vis[mx],n,clor[mx];
void dfs(ll u,ll clr=-1){

ll a,b;
for(auto i:v[u]){

    if (i.F==clr) continue;
        if(i.S&1){
            clor[i.F]=1-clor[u];
        }
        else {
            clor[i.F]=clor[u];

        }
        dfs(i.F,u);

}
}


int main(){//read(x);
fast;
ll a,b,c,d,e,f,g,h,l,i,j=0,k,t;

    cin>>n;
    for(i=1;i<n;i++){
        cin>>a>>b>>c;
        v[a].pb(mp(b,c));
        v[b].pb(mp(a,c));
    }

    memset(clor,-1,n+1);
    clor[1]=0;
    dfs(1,0);

    for(i=1;i<=n;i++)cout<<clor[i]<<endl;
}





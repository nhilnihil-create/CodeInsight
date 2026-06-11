#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FAST ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
#define pb push_back
#define MOD 1000000007
#define sz5 100005
#define sz6 1000005
#define UP upper_bound
#define LB lower_bound
#define F first
#define S second
#define PI pair<int,int>
#define PL pair<ll,ll>
#define VI vector<int>
#define VL vector<ll>

VI gr[sz5];
int up[sz5], dwn[sz5];

void dfs(int idx, int l, bool mk[]){
    // cout<<' '<<idx<<' '<<l<<endl;
    mk[idx]=true;
    up[idx]=l;
    int mx=0;
    for(auto it: gr[idx]){
        if(!mk[it])
            dfs(it, l+1, mk);
        up[it]=max(up[it], l+1);
        mx=max(mx, dwn[it]);
    }

    dwn[idx]=1+mx;
}

int main() {
    FAST

    int n,m,x,y,la,lb;
    cin>>n>>m;
    for(la=1;la<=m;la++){
        cin>>x>>y;
        gr[x].pb(y);
    }

    bool mk[n+4]={0};
    for(la=1;la<=n;la++)
    if(!mk[la])
        dfs(la, 0, mk);

    int mx=0;
    for(la=1;la<=n;la++)
        mx=max(mx, up[la]+dwn[la]);

    // cout<<endl<<endl;
    // for(la=1;la<=n;la++)
    //     cout<<up[la]<<' '<<dwn[la]<<endl;

    cout<<mx-1<<endl;

    return 0;
}
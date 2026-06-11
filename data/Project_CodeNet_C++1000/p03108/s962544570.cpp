#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
#define PI 3.14159265359
#define INF 1000100100
#define all(x) (x).begin(),(x).end()
typedef long long ll;
#define P pair<ll, ll>
#define PP pair<P,P>
using namespace std;

int main(){
    ll n,m; cin >> n >> m;
    vector<P> is(m);
    rep(i,m) cin >> is[i].first >> is[i].second;
    vector<int> id(n);
    rep(i,n) id[i]=i;
    vector<ll> sz(n,1);
    vector<ll> ans(m);
    ans[m-1]=((n-1)*n)/2;

    for(int i=m-1; i>=1; i--){
        int f=is[i].first;
        int s=is[i].second;
        f--; s--;
        int fp=f;
        int sp=s;
        while(fp!=id[fp]){
            fp=id[fp];
            //cout << fp << ' ' << id[f] << ' ' << "fff" << endl;
        }
        while(sp!=id[sp]){
            sp=id[sp];
        }
        //cout << fp << ' ' << sp << endl;
        if(fp==sp){
            ans[i-1]=ans[i];
            continue;
        }
        ll tmp=sz[fp]*sz[sp];
        ans[i-1]=ans[i]-tmp;
        int mip=min(fp,sp);
        int map=max(fp,sp);
        sz[mip]=sz[fp]+sz[sp];
        id[map]=mip;
    }
    rep(i,m) cout << ans[i] << endl;
return 0;
}


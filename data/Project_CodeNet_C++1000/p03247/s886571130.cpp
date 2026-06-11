#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll n, xi[1010], yi[1010], c[2], m, ans[40];
ll dx[]={1,-1,0,0};
ll dy[]={0,0,1,-1};
char ch[]={'R','L','U','D'};

void fuck(ll x,ll y,ll w){
    if (w>m) return;
    ll mn=1e100, d;
    for (int i=0;i<4;++i){
        ll t=abs(x+dx[i]*ans[w])+abs(y+dy[i]*ans[w]);
        if (t<mn) mn=t, d=i;
    }
    putchar(ch[d]);
    fuck(x+dx[d]*ans[w],y+dy[d]*ans[w],w+1);
}

int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>xi[i]>>yi[i];
        c[(xi[i]+yi[i])&1]++;
    }
    if (c[0]&&c[1]) return puts("-1"), 0;
    for (int i=31;i>=0;--i)
        ans[++m]=1ll<<i;
    if (c[0]) ans[++m]=1;
    cout<<m<<endl;
    for (int i=1;i<=m;++i) cout<<ans[i]<<' ';
    cout<<endl;
    for (int i=1;i<=n;++i){
        fuck(-xi[i],-yi[i],1);
        puts("");
    }
}
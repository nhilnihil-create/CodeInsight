#include<bits/stdc++.h>
#define ll long long
#define int long long
#define sz(c) c.size()
#define fr first
#define sc second
#define pb push_back
#define sz(c) c.size()
#define ppb  pop_back
#define all(a)      (a).begin(),(a).end()
#define rep(i,a,n)   for( int i=a ; i<n ; i++)
#define U 1000000007
#define N 200005
#define ins insert
using namespace std;
int n,a[N],t[400009],dp[N];
pair<int,int>p[N];
void build(int v, int tl, int tr){
    if(tl==tr){
        t[v]=a[tl];
        return;
    }
    int tm=(tl+tr)/2;
    build(2*v,tl,tm);
    build(2*v+1,tm+1,tr);
    t[v]=max(t[2*v],t[2*v+1]);
}
void upd(int v, int tl, int tr, int pos, int val){
    if(tl==tr){
        t[v]=val;
        return;
    }
    int tm=(tl+tr)/2;
    if(pos<=tm) upd(2*v,tl,tm,pos,val);
    else upd(2*v+1,tm+1,tr,pos,val);
    t[v]=max(t[2*v],t[2*v+1]);
}
int get(int v, int tl, int tr, int l, int r){
    if(l>r) return 0;
    if(l==tl && r==tr) return t[v];
    int tm=(tl+tr)/2;
    return max(get(2*v,tl,tm,l,min(r,tm)),
            get(2*v+1,tm+1,tr,max(l,tm+1),r));
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin>>n;
    build(1,1,n);
    rep(i,0,n) cin>>p[i].fr;
    rep(i,0,n) cin>>p[i].sc;
    rep(i,0,n){
        int z=get(1,1,n,1,p[i].fr-1);
        dp[i]=p[i].sc+z;
        upd(1,1,n,p[i].fr,dp[i]);
    }
    int ma=0;
    rep(i,0,n) ma=max(ma,dp[i]);
    cout<<ma;



}
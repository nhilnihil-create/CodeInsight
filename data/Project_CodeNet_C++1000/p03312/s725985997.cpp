#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define dbg(x...) do{cout << "\033[32;1m" << #x << "->" ; err(x);} while(0)
void err(){cout << "\033[39;0m" << endl;}
template<template<typename...> class T,typename t,typename... A>
void err(T<t> a,A... x){for (auto v:a) cout << v << ' '; err(x...);}
template<typename T,typename... A>
void err(T a,A... x){cout << a << ' '; err(x...);}
#else
#define dbg(...)
#endif
typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
template<class T> using vc=vector<T>;
template<class T> using vvc=vc<vc<T>>;
template<class T> void mkuni(vector<T>&v)
{
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
}
template<class T>
void print(T x,int suc=1)
{
    cout<<x;
    if(suc==1) cout<<'\n';
    else cout<<' ';
}
template<class T>
void print(const vector<T>&v,int suc=1)
{
    for(int i=0;i<v.size();i++)
        print(v[i],i==(int)(v.size())-1?suc:2);
}
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
const int maxn=2e5+7;

int dp[maxn][4];
ll s[maxn],tot,mx,mn,now,ans=1e18,a[maxn];
int px=1,py=1,n;

void upd(){
    if(now<mn) mn=now;
    else if(now>mx) mx=now;
}

void solve()
{
    for(int mid=1;mid<=n;++mid)
    {
        while(px<=mid&&2ll*s[px]<=s[mid]) ++px;
        while(py<=n&&2ll*s[py]<=tot+s[mid]) ++py;

        //dbg(px,py);
        for(int i=px;i>=px-1;i--)
            for(int j=py;j>=py-1;j--)
            {
                mx=mn=s[i];
                now=s[mid]-s[i]; upd();
                now=s[j]-s[mid]; upd();
                now=tot-s[j];    upd();
                ans=min(ans,mx-mn);
                //dbg(mx,mn);
            }
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];

    for(int i=1;i<=n;++i)
    {
        s[i]=s[i-1]+a[i];
    }
    s[n+1]=tot=s[n];
    solve();
    print(ans);
    return 0;
}
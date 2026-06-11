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
const int mod=998244353;
const int maxn=1e5+7;

#define N 100010
#define lowbit(x) x&-x
int c[N*10];
int n,a[N],s[N*10];
void add(int x){
    for(int i=x;i<=2*N;i+=lowbit(i))c[i]++;
}
ll query(int x){
    ll sum=0;
    for(int i=x;i>0;i-=lowbit(i))sum+=c[i];
    return sum;
}
bool check(int x){
    for(int i=1;i<=2*N;i++)c[i]=0;
    s[0]=0;
    for(int i=1;i<=n;i++)
        s[i]=s[i-1]+(a[i]>=x?1:-1);
    ll sum=0;
    for(int i=0;i<=n;i++){
        sum+=query(s[i]+N);
        add(s[i]+N);
    }
    return sum>=1ll*n*(n+1)/4;
}
int main(){
    cin>>n;
    int l=0,r=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        r=max(r,a[i]);
    }
    int ans=0;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid))l=mid+1;
        else r=mid-1;
    }
    cout<<r<<endl;
}
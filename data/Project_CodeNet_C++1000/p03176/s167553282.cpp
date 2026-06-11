#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
#define ll long long int

template<typename T>
struct range_max{
    vector<T> tr;
    void build(int l,int r,int v=1){
        if(l==r){
            //tr[v]=a[r];
            return;
        }
        int mid=(l+r)/2;
        build(l,mid,2*v);
        build(mid+1,r,2*v+1);
        tr[v]=max(tr[2*v],tr[2*v+1]);
    }

    void update(int l,int r,int pos,T val,int v=1){
        if(pos<l || pos>r)return;
        if(l==r && l==pos){
            tr[v]=val;
            return;
        }
        else if(l==r)return;
        int mid=(l+r)/2;
        update(l,mid,pos,val,2*v);
        update(mid+1,r,pos,val,2*v+1);
        tr[v]=max(tr[2*v+1],tr[2*v]);
    }

    T query(int l,int r,int st,int end,int v=1){
        //debug(l,r,st,end);
        if(st>end)return 0;
        if(l==st && r==end)return tr[v];
        int mid=(l+r)/2;
        T t1=query(l,mid,st,min(mid,end),2*v);
        T t2=query(mid+1,r,max(st,mid+1),end,2*v+1);
        return max(t1,t2);
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> h(n);
    for(auto &x:h)cin>>x;
    vector<int> a(n);
    for(auto &x:a)cin>>x;
    range_max<ll> seg_tree;
    seg_tree.tr.resize(4*n+1);
    for(int i=0;i<n;i++){
        ll mx=seg_tree.query(0,n-1,0,h[i]-1);
        seg_tree.update(0,n-1,h[i]-1,mx+a[i]);
    }
    ll ans=seg_tree.query(0,n-1,0,n-1);
    cout<<ans<<"\n";
    return 0;
}
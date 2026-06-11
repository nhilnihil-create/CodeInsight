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

int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    vector<int> a(n);
    for(auto &x:a)scanf("%d",&x);
    ll ans=0;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(i+j>n || i+j>k || i+j==0)continue;
            priority_queue<int,vector<int>, greater<int>> q;
            ll s=0;
            debug(i,j);
            for(int l=0;l<i;l++){
                s+=a[l];
                q.push(a[l]);
            }
            for(int l=0;l<j;l++){
                s+=a[n-1-l];
                q.push(a[n-1-l]);
            }
            debug(s);
            int cur=i+j;
            while(q.top()<0 && cur<k){
                debug(q.top());
                cur++;
                s-=q.top();
                q.pop();
                if(q.empty())break;
            }
            ans=max(s,ans);
        }
    }
    printf("%lld\n",ans);
    return 0;
}
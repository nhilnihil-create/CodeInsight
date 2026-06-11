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
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &x:a)cin>>x;
    auto get_sum=[&](int l,int r){
        ll s=0;
        for(int i=l;i<=r;i++){
            s+=a[i];
        }
        return s;
    };
    vector<vector<ll>> dp(n+1,vector<ll> (n+1));
    for(int L=n-1;L>=0;L--){
        for(int R=L;R<n;R++){
            debug(L,R);
            if(L==R){
                dp[L][R]=0;
                continue;
            }
            ll su=get_sum(L,R);
            dp[L][R]=1e18;
            for(int i=L;i<R;i++){
                //debug(dp[L][i],dp[i+1][R],su);
                dp[L][R]=min(dp[L][R],dp[L][i]+dp[i+1][R]+su);
            }
        }
    }
    cout<<dp[0][n-1]<<"\n";
    return 0;
}

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

ll mod=1e9+7;

int main(){
    int n;
    cin>>n;
    vector<vector<int>> a(n,vector<int> (n));
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>a[i][j];
    int maxn=1<<n;
    vector<ll> dp(maxn,0);
    dp[maxn-1]=1;
    for(int i=maxn-2;i>=0;i--){
        int cur=i;
        //get the current person by counting the number of already assigned bits
        int mn=0;
        while(cur!=0){
            mn+=(cur&1);
            cur=cur>>1;
        }
        //debug(mn);
        for(int k=0;k<n;k++){
            if(a[mn][k] && !(i&(1<<k))){
                dp[i]+=dp[i|(1<<k)];
                dp[i]%=mod;
            }
        }
    }
    cout<<dp[0]<<"\n";
    return 0;
}
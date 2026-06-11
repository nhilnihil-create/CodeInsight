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
    vector<vector<int>> a(n,vector<int> (3));
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++)cin>>a[i][j];
    }
    vector<vector<int>> dp(n,vector<int> (3));
    dp[0]=a[0];
    for(int i=1;i<n;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                if(j!=k){
                    dp[i][j]=max(dp[i][j],dp[i-1][k]+a[i][j]);
                }
            }
        }
    }
    cout<<*max_element(dp[n-1].begin(),dp[n-1].end())<<"\n";
    return 0;
}

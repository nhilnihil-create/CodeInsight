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
    string s,t;
    int n,m;
    cin>>s>>t;
    n=s.length();
    m=t.length();
    vector<vector<int>> dp(n+1,vector<int> (m+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            dp[i][j]=max({dp[i-1][j],dp[i][j-1],dp[i][j]});
        }
    }
    string ans="";
    int row=n,col=m;
    while(row !=0 && col!=0){
        debug(row,col);
        if(s[row-1]==t[col-1]){
            if(dp[row][col]==dp[row-1][col-1]+1){
                ans+=s[row-1];
                row=row-1;
                col=col-1;
                continue;
            }
        }
        else if(dp[row][col]==dp[row-1][col]){
            row=row-1;
        }
        else if(dp[row][col]==dp[row][col-1]){
            col=col-1;
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<"\n";
    return 0;
}
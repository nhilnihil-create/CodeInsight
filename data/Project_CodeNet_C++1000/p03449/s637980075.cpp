#include <bits/stdc++.h>

#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,n,s) for(int i=(s);i<(n);i++)
#define rrep(i,n) for(int i=(n-1);i>=0;i--)
#define rreps(i,n,s) for(int i=s;i>=n;i--)
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

using ll = long long;
using namespace std;
constexpr long long MAX = 5100000;
constexpr long long INF = 1LL << 60;
constexpr int MOD = 1000000007;

int main(){
cin.tie(0);
ios::sync_with_stdio(false);
int n;
cin>>n;
vector<vector<int>>a(2,vector<int>(n,0));
rep(i,2){
    rep(j,n)cin>>a[i][j];
}
vector<vector<ll>>s(2,vector<ll>(n,0));
s[0][0]=a[0][0];
s[1][n-1]=a[1][n-1];
reps(i,n,1){
    s[0][i]=s[0][i-1]+a[0][i];
    s[1][n-1-i]=s[1][n-1-i+1]+a[1][n-1-i];
}
ll max_val=-1;
rep(i,n){
    max_val=max(max_val,s[0][i]+s[1][i]);
}
cout<<max_val<<endl;
return 0;
}
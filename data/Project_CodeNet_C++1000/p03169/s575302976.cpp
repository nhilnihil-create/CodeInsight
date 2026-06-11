#include<bits/stdc++.h>
using namespace std;

// template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
// template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
 
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define INF 10000000000
#define MOD 1000000007
using ll = long long;
using pint = pair<int,int>;
using pll = pair<ll,ll>;
using Graph = vector<vector<int>>;
int N; 
vector<vector<vector<double>>> dp(310,vector<vector<double>>(310,vector<double>(310,0)));
vector<vector<vector<double>>> flag(310,vector<vector<double>>(310,vector<double>(310,0)));

//更新順序が非自明
double rec(int c1,int c2,int c3){
    if(flag[c1][c2][c3]) return dp[c1][c2][c3];
    if(c1==0&&c2==0&&c3==0)return 0.0;
    flag[c1][c2][c3] = 1;
    double res = 1;
    if(c1>0) res += rec(c1-1,c2,c3)*c1/N;
    if(c2>0) res += rec(c1+1,c2-1,c3)*c2/N;
    if(c3>0) res += rec(c1,c2+1,c3-1)*c3/N;
    res /= (1 - (double)(N-c1-c2-c3)/N);
    return dp[c1][c2][c3] = res;
}

int main(){
    cin>>N;
    // double dp[310][310][310];
    rep(i,310)rep(j,310)rep(k,310)dp[i][j][k]=0;
    int i = 0, j = 0, k = 0;
    rep(d,N){
        int a;  cin>>a;
        if(a==1)i++;
        else if(a==2)j++;
        else k++;
    }
    cout<<setprecision(12)<<rec(i,j,k)<<endl;
}
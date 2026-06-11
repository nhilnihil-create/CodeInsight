#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i < (ll)(n); i++)
#define INF 10000000000
#define MOD 1000000007
using ll = long long;
using pint = pair<int,int>;

int N;
double dp[310][310][310];
vector<int> a;

double rec(int i, int j, int k){
    if(dp[i][j][k]>=0) return dp[i][j][k];
    if(i==0&&j==0&&k==0)return 0.0;
    double res = N;
    if(i>0) res += rec(i-1,j,k)*i;
    if(j>0) res += rec(i+1,j-1,k)*j;
    if(k>0) res += rec(i,j+1,k-1)*k;
    res /= (double)(i+j+k);
    return dp[i][j][k] = res;
}

int main(){
    cin>>N;
    a.reserve(N);
    rep(i,N)cin>>a[i];
    rep(i,310)rep(j,310)rep(k,310)dp[i][j][k]=-1;
    int i = 0,j = 0,k = 0;
    rep(n,N){
        if(a[n]==1)i++;
        else if(a[n]==2)j++;
        else if(a[n]==3)k++;
    }
    
    cout<<setprecision(10)<<rec(i,j,k)<<endl;
}
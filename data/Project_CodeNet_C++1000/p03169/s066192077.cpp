#include <bits/stdc++.h>
#include <vector> 
# include <cstdint>
#define FOR(i,l,r) for(int i=(l);i<(r);++i)
#define RFOR(i,l,r) for(int i=(l);i>=(int)(r);i--)
#define rep(i,n)  FOR(i,0,n)
#define rrep(i,n)  RFOR(i,n-1,0)

#define int long long
using namespace std;
const int MX = 1e6;
const int inf = 1e13;
const int mod = 1e9+7;
#define ll long long
double dp[305][305][305];
int n;
vector<int> a;
void f(int i, int j, int k) {
    double nn0 = n-i-j-k;
    double bun = 1.0-(double)(nn0/(double)n);
    if(bun==0) dp[i][j][k]=0;
    else dp[i][j][k] =1.0/bun;
     
    if(i>0){
        if(dp[i-1][j][k]==-1) f(i-1,j,k);
        dp[i][j][k] += dp[i-1][j][k]*(i)/n/bun;
    }
    if(j>0){
        if(dp[i+1][j-1][k]==-1) f(i+1,j-1,k);
        dp[i][j][k] += dp[i+1][j-1][k]*(j)/n/bun;
    }
    if(k>0){
        if(dp[i][j+1][k-1]==-1) f(i,j+1,k-1);
        dp[i][j][k] += dp[i][j+1][k-1]*(k)/n/bun;
    }
}
signed main() {
    cin >> n;
    a.resize(n);
    int n1 = 0;
    int n2 = 0;
    int n3 = 0;
    rep(i,n) {
        cin >> a[i];
        if(a[i]==1) n1++;
        else if(a[i]==2) n2++;
        else if(a[i]==3) n3++;
    }
    rep(i,305)rep(j,305)rep(k,305) dp[i][j][k]=-1;
    f(n1,n2,n3);
    cout << setprecision(20)<<dp[n1][n2][n3] << endl;




  return 0;
}


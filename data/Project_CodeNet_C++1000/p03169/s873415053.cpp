#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define ve vector

int n;
double dp[310][310][310];

double rec(int i, int j, int k){
    if(dp[i][j][k] >= 0) return dp[i][j][k];
    if(i==0&&j==0&&k==0) return 0.0;

    double res = 0.0;
    if(i>0) res += rec(i-1,j,k) * i;
    if(j>0) res += rec(i+1,j-1,k) * j;
    if(k>0) res += rec(i,j+1,k-1) * k;
    res += n;
    res *= 1.0/(i+j+k);
    return dp[i][j][k] = res;
}

int main(){
    cin >> n;
    int i=0, j=0, k=0;
    for(int x = 0; x < n; x++){
        int a;
        cin >> a;
        if(a==1)i++;
        if(a==2)j++;
        if(a==3)k++;
    }
    memset(dp,-1,sizeof(dp));
    dp[0][0][0] = 0.0;
    double ans = rec(i,j,k);
    printf("%.10f\n", ans); 
    return 0;
}
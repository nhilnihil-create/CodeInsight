#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(ll)n;i++)


int N;
double dp[310][310][310];

double rec(int i, int j, int k){
    if(dp[i][j][k] >= 0) return dp[i][j][k];
    if(i == 0 && j == 0 && k == 0) return 0.0;

    double res = 0.0;
    if(k > 0) res += rec(i,j+1,k-1) * k;
    if(j > 0) res += rec(i+1,j-1,k) * j;
    if(i > 0) res += rec(i-1,j,k) * i;
    res += N;
    res *= 1.0 / (i+j+k);

    return dp[i][j][k] = res;
}

int main(){
    cin >> N;
    int i=0,j=0,k=0;
    rep(idx, N){
        int a; cin >> a;
        if(a==1) i++;
        else if(a==2) j++;
        else k++;
    }

    memset(dp, -1, sizeof(dp));

    cout << fixed << setprecision(10) << rec(i,j,k) << endl;
}
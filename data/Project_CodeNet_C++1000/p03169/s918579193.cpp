#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB emplace_back

using namespace std;

const int N = 310;

long double dp[N][N][N];

long long int a1, a2, a3;

int main () {
    cout << setprecision(12) << fixed;
    long long int n;
    cin >> n;
    for(int i = 0 ; i < n ; i++ ) {
        int x;
        cin >> x;
        if(x==1)a1++;
        if(x==2)a2++;
        if(x==3)a3++;
    }
    dp[0][0][0]=0;
    for(int k = 0 ; k <= n ; k++ ) {
        for(int j = 0 ; j <= n ; j++ ) {
            for(int i = 0 ; i <= n ; i++ ) {
                if(i+j+k>n||i+j+k==0)continue;
                long double ii = i, jj = j, kk = k;
                if(i!=0)dp[i][j][k]+=ii*(dp[i-1][j][k]+1);
                if(j!=0)dp[i][j][k]+=jj*(dp[i+1][j-1][k]+1);
                if(k!=0)dp[i][j][k]+=kk*(dp[i][j+1][k-1]+1);
                dp[i][j][k]+=n-ii-jj-kk;
                dp[i][j][k]/=i+j+k;
            }
        }
    }
    cout << dp[a1][a2][a3] << '\n';
}

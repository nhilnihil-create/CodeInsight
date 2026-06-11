#include<bits/stdc++.h>
using namespace std;
using ll = long long;
long double PI= 3.141592653589793238463;
const int N = 1e5+5;
const int MOD = 1e9+7;

ll a[100005][5];
ll b[100005];
ll c[100005];
ll dp[100005][5];
int n,k;

void D()
{
    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++){
            for(int k=1;k<=3;k++){
                if( j != k ) dp[i][j] = max( dp[i-1][k] + a[i][j] , dp[i][j] ) ;
            }
        }
    }
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++){
            cin>>a[i][j];
        }
    }
 D();
 cout<< max( dp[n][1] , max( dp[n][2] , dp[n][3] ) );
    return 0;
}


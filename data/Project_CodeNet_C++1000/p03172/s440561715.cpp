#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 8;
const int mod = 1e9 + 7;
int n , a[N] , T;

int dp[101][N];

int add(int x , int y){return (x % mod + y % mod) % mod;}
int sub(int x , int y){return (x % mod - y % mod + mod) % mod;}

int main(){
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);  
    cin >> n >> T;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
    }

    dp[0][0] = 1 ;

    for(int i = 1 ; i <= n ; i++){
        for(int j = 0 ; j <= T ; j++){
            int rem = j - a[i] - 1;
            if(rem < 0) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = sub(dp[i - 1][j] , dp[i - 1][rem]);
        }
        for(int u = 1 ; u <= T ; u++){
            dp[i][u] = add(dp[i][u] , dp[i][u - 1]);
        }
    }
    cout << dp[n][T] << endl;
  return 0;
}



/*for( int i = 1 ; i <= n ; i++ ){
        for( int j = 0 ; j <= T ; j++ ){
            for( int l = 0 ; l <= a[i] ; l++ )
                if( j >= l ){
                dp[i][j] += dp[i-1][j-l];
            }
        }
    }*/
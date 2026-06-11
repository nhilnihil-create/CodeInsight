#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    long long n = 0 , candies = 0 , mod = 1000000007 ;
    cin >> n >> candies ;
    long long a[n+1] , temp[candies+1] , ways[n+1][candies+1] , ptr = 0 ;
    for(long long i = 1 ; i <= n ; i++)
        cin >> a[i] ;
    for(long long i = 0 ; i <= n ; i++)
        for(long long j = 0 ; j <= candies ; j++)
            ways[i][j] = 0 , temp[j] = 0 ;
    ways[0][0] = 1 ;
    for(long long i = 1 ; i <= n ; i++){
        temp[0] = ways[i-1][0] ;
        for(long long j = 1 ; j <= candies ; j++)
            temp[j] = (temp[j-1] % mod + ways[i-1][j] % mod) % mod ;
        for(long long j = 0 ; j <= candies ; j++){
            ways[i][j] = temp[j] ;
            if(j-a[i]-1 >= 0) ways[i][j] = (temp[j] - temp[j-a[i]-1] + mod) % mod ;
        }
    }
    cout << ways[n][candies] ;
}

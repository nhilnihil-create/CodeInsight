#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    int n = 0 , k = 0 , mn = INT_MAX ;
    cin >> n >> k ;
    int arr[n+1] ;
    bool TaroWins[k+1][n+1] , dp[k+1] ;
    for(int i = 1 ; i <= n ; i++)
        cin >> arr[i] ;
    sort(arr+1, arr+n+1) ;
    mn = arr[1] ;
    for(int i = 0 ; i <= k ; i++){
        dp[i] = false ;
        for(int j = 0 ; j <= n ; j++)
            TaroWins[i][j] = false ;
    }
    for(int i = 1 ; i <= k ; i++){
        if(mn > i) continue ;
        else{
            for(int j = 1 ; j <= n ; j++){
                if(i-arr[j] >= 0) dp[i] = !dp[i-arr[j]] ;
                if(dp[i]) break ;
            }
        }
        for(int j = 1 ; j <= n ; j++){
            if(mn > i){
                TaroWins[i][j] = false ;
                continue ;
            }
            if(i-arr[j] >= 0) TaroWins[i][j] = !(TaroWins[i-arr[j]][j]) ;
            TaroWins[i][j] = TaroWins[i][j] || TaroWins[i][j-1] ;
        }
    }
    /*for(int i = 1 ; i <= k ; i++){
        for(int j = 1 ; j <= n ; j++)
            cout << TaroWins[i][j] << " " ;       
        cout << dp[i] << "\n" ;
    }*/
    if(dp[k]) cout << "First" ;
    else cout << "Second" ;
}
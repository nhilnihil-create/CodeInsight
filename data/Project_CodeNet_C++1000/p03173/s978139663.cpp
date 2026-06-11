#include <iostream>
#include <vector>

using namespace std ;

int main(){
    int n ;
    cin >> n ;
    
    vector<long long int> a(n) ;
    
    for (int i=0 ; i<n ; i++)
        cin >> a[i] ;
    
    vector<vector<long long int> > dp(n, vector<long long int> (n, LONG_MAX)) ;
    vector<vector<long long int> > cost(n, vector<long long int> (n, LONG_MAX)) ;
    
    for (int i=n-1 ; i>=0 ; i--){
        for (int j=i ; j<n ; j++){
            if (i==j){
                dp[i][j] = a[i] ;
                cost[i][j] = 0 ;
            }
            else{
                for (int k=i ; k<=j-1 ; k++){
                    long long int temp_cost = dp[i][k] + dp[k+1][j] + cost[i][k] + cost[k+1][j] ;
                    if (temp_cost < cost[i][j]){
                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j]) ;
                        cost[i][j] = temp_cost ;
                    }
                }
            }
        }
    }
    
    cout << cost[0][n-1] << "\n" ;
    
    return 0 ;
}

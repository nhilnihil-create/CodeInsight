#include <iostream>
#include <vector>
#include <iomanip>

using namespace std ;

void print2dvector(vector<vector<double> > v){
    for (int i=0 ; i<v.size() ; i++){
        for (int j=0 ; j<v[0].size() ; j++)
            cout << v[i][j] << " " ;
        cout << "\n" ;
    }
}

double prob(vector<double> &p){
    int n = p.size() ;
    vector< vector < double> > dp(n+1, vector<double> (n+1, 0.0)) ;
    dp[0][0] = 1 ;
    
    for (int i=1 ; i<=n ; i++){
        for (int j=0 ; j<=n ; j++){
            if (j == 0)
                dp[i][j] = dp[i-1][j]*(1-p[i-1]) ;
            else
                dp[i][j] = dp[i-1][j]*(1-p[i-1]) + dp[i-1][j-1]*p[i-1] ;
        }
    }
    
    double probability = 0 ;
    for (int i=n/2+1 ; i<=n ; i++ )
        probability += dp[n][i] ;
    
//    print2dvector(dp) ;
    
    return probability ;
}

int main(){
    int n ;
    cin >> n ;
    
    vector<double> p(n) ;
    
    for (int i=0 ; i<n ; i++)
        cin >> p[i] ;
    
    cout << setprecision(10) << prob(p) << "\n" ;
    
    return 0 ;
}

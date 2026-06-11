#include <iostream>
#include <vector>

using namespace std ;

int num = 1000000007 ;

long long int num_paths(vector<vector <char> > a){
    int H = a.size(), W = a[0].size() ;
    
    vector<vector<long long int> > dp(H+1, vector<long long int>(W+1, 0)) ;
    
    for (int i=1 ; i<=H ; i++){
        for (int j=1 ; j<=W ; j++){
            if (a[i-1][j-1] == '#')
                dp[i][j] = 0 ;
            else if (i==1 && j==1){
                dp[i][j] = 1 ;
            }
            else
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % num ;
        }
    }
    
    return dp[H][W] ;
}

int main(){
    int H, W ;
    cin >> H >> W ;
    
    vector<vector <char> > a (H, vector<char> (W, '.')) ;
    
    for (int i=0 ; i<H ; i++){
        for (int j=0 ; j<W ; j++)
            cin >> a[i][j] ;
    }
    
    cout << num_paths(a) << "\n" ;
    
    return 0 ;
}

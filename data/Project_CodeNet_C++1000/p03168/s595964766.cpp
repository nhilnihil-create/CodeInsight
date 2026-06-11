#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    int n = 0 ; 
    cin >> n ;
    double bais[n+1] , probab[n+1][n+1] , ans = 0 ;
    for(int i = 1 ; i <= n ; i++)
        cin >> bais[i] ;
    for(int i = 0 ; i <= n ; i++)
        for(int j = 0 ; j <= n ; j++)
            probab[i][j] = 0 ;
    probab[0][0] = 1 ;
    for(int i = 1 ; i <= n ; i++)
        probab[i][0] = probab[i-1][0]*(1-bais[i]) ;
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= i ; j++)
            probab[i][j] = bais[i]*(probab[i-1][j-1]) + probab[i-1][j]*(1-bais[i]) ;
    /*for(int i = 1 ; i <= n ; i++){
        for(int j = 0 ; j <= n ; j++)
            cout << probab[i][j] << " " ;
        cout << "\n" ;
    }*/
    for(int i = n/2+1 ; i <= n ; i++)
        ans += probab[n][i] ;
    cout << fixed << setprecision(10) << ans ;
}
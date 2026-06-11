#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    int n = 0 ; 
    cin >> n ; 
    int a[n+1] = {0} , b[n+1] = {0} , c[n+1] = {0} , happiness[n+1][3] = {{0}} , maxhappiness = 0 ;
    for(int i = 1 ; i <= n ; i++)
        cin >> a[i] >> b[i] >> c[i] ;
    happiness[1][0] = a[1] , happiness[1][1] = b[1] , happiness[1][2] = c[1] ;
    for(int i = 2 ; i <= n ; i++){
        happiness[i][0] = a[i] + max(happiness[i-1][1] , happiness[i-1][2]) ;
        happiness[i][1] = b[i] + max(happiness[i-1][0] , happiness[i-1][2]) ;
        happiness[i][2] = c[i] + max(happiness[i-1][1] , happiness[i-1][0]) ;
    }
    maxhappiness = max(happiness[n][0] , max(happiness[n][1] , happiness[n][2])) ;
    cout << maxhappiness ;
}

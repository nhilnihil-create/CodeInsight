#include <bits/stdc++.h>
using namespace std;
bool isSafe(int i , int j, int n , int k){
    if(i >= 0 && j >= 0 && i <= k && j <= n)
        return true ;
    return false ;
}
int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    int n = 0 , k = 0 , mn = INT_MAX ;
    cin >> n >> k ;
    int arr[n+1] ;
    bool TaroWins[k+1][n+1] ;
    for(int i = 1 ; i <= n ; i++)
        cin >> arr[i] ;
    sort(arr+1, arr+n+1) ;
    mn = arr[1] ;
    for(int i = 0 ; i <= k ; i++)
        for(int j = 0 ; j <= n ; j++)
            TaroWins[i][j] = false ;
    for(int i = 1 ; i <= k ; i++){
        for(int j = 1 ; j <= n ; j++){
            if(isSafe(i-arr[j] , j , n , k)) TaroWins[i][j] = !(TaroWins[i-arr[j]][n]) ;
            TaroWins[i][j] = TaroWins[i][j] || TaroWins[i][j-1] ;
        }
    }
    if(TaroWins[k][n]) cout << "First" ;
    else cout << "Second" ;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    ll n = 0 ; 
    cin >> n ; 
    ll a[n+1] , sum[n+1] , minCost[n+1][n+1] , temp = 0 ;
    sum[0] = 0 ;
    for(ll i = 1 ; i <= n ; i++)
        cin >> a[i] , sum[i] = sum[i-1] + a[i] ;
    for(ll i = 0 ; i <= n ; i++)
        for(ll j = 0 ; j <= n ; j++)
            minCost[i][j] = 0 ;
    for(ll i = 1 ; i <= n-2+1 ; i++)
        minCost[2][i] = a[i] + a[i+1] ;
    for(ll L = 3 ; L <= n ; L++){
        for(ll i = 1 ; i <= n-L+1 ; i++){
            temp = LONG_MAX ;
            for(ll j = 1 ; j <= L-1 ; j++)
                temp = min(temp , minCost[j][i]+minCost[L-j][i+j]) ;
            minCost[L][i] = sum[i+L-1]-sum[i-1] + temp ;
        }
    }
    cout << minCost[n][1] ;
}

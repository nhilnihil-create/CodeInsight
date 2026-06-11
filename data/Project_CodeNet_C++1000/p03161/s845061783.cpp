#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    int n = 0 , k = 0 ; 
    cin >> n >> k ; 
    vector<int> height(n+1), cost(n+1, INT_MAX) ;
    for(int i = 1 ; i <= n ; i++)
        cin >> height[i] ;
    cost[1] = 0 ;
    for(int i = 2 ; i <= n ; i++)
        for(int j = 1 ; j <= k ; j++)
            if(i-j > 0)
                cost[i] = min(cost[i-j] + abs(height[i]-height[i-j]) , cost[i]) ;
    cout << cost[n] ;
}

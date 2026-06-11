#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    int n = 0 ; 
    cin >> n ; 
    vector<int> height(n+1), cost(n+1) ;
    for(int i = 1 ; i <= n ; i++)
        cin >> height[i] ;
    cost[1] = 0 , cost[2] = abs(height[2]-height[1]) ;
    for(int i = 3 ; i <= n ; i++)
        cost[i] = min(cost[i-2] + abs(height[i]-height[i-2]) , cost[i-1] + abs(height[i]-height[i-1])) ;
    cout << cost[n] ;
}

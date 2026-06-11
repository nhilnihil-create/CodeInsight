/*
    coded by - PATHAKCODES ~~Revamped
    AIT PUNE , INDIA 
     
    "The Key is not will to win ......everybody has that "
    "It is will to prepare that is important"  
     
*/
     
#include <bits/stdc++.h>
 
using namespace std ;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
#define pb push_back
const ll k = 1e9 +7;



int main ()
{
    IOS
    int n ; cin >> n ;

    vector<int> h(n,0);

    for(int i = 0;i < n ; i++)
         cin >> h[i];

     vector<int> dp(n,0);
     dp[0] = 0;
     dp[1] = abs(h[1]-h[0]);

     for(int i= 2 ; i < n ; i++){
        dp[i] = min(abs(h[i]-h[i-1])+dp[i-1],
         abs(h[i]-h[i-2])+ dp[i-2]);
     }

     cout << dp[n-1] << endl;
}


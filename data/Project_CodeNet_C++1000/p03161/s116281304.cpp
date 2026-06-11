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
    int n, k ; cin >> n >> k;

    vector<int> h(n,0);

    for(int i = 0;i < n ; i++)
         cin >> h[i];

     vector<int> dp(n,INT_MAX);
     dp[0] = 0;
     dp[1] = abs(h[1]-h[0]);

     for(int i= 2 ; i < n ; i++){
        for(int j = 1 ; j <= k && i-j >=0 ; j++){
            if(abs(h[i]-h[i-j])+dp[i-j] < dp[i])
            dp[i] = abs(h[i]-h[i-j])+dp[i-j];
        }
       
     }

     cout << dp[n-1] << endl;
}


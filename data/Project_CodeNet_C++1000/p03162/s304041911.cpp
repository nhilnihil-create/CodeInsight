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
    int n; 
    cin >>n;


    vector<vector<int>> dp(n, vector<int>(3,0));

    for(int i = 0; i < n ; i++){

        int a , b , c;
        cin >> a >> b >> c;

        if(i==0){
            dp[0][0] =a;
            dp[0][1] =b;
            dp[0][2] =c;
        }else {
            dp[i][0] = max(dp[i-1][1],dp[i-1][2])+a;
            dp[i][1] = max(dp[i-1][0], dp[i-1][2])+b;
            dp[i][2] = max(dp[i-1][0], dp[i-1][1])+c;
        }


    }

    cout << max(dp[n-1][0],max(dp[n-1][1], dp[n-1][2]));

  
}


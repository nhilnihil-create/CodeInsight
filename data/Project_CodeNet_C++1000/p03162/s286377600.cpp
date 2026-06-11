#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
#define FI(z,n) for(int j=z; j<=n; j++)
#define FL(z,n) for(l j=z; j<=n; j++)
 
#define inf 10000000000
#define mod 1000000007
 
void In_Out(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt", "w", stderr);
    #endif
}

struct Act{
    ll A, B, C;
};
 
 
int main(){
 
    // In_Out();

    ll n, a, b, c;
    cin >> n;

    Act arr[n];

    for(ll i=0; i<n; i++){
        cin >> arr[i].A >> arr[i].B >> arr[i].C;
    }

    ll dp[n][3];
    dp[0][0] = arr[0].A;
    dp[0][1] = arr[0].B;
    dp[0][2] = arr[0].C;

    for(ll i=1; i<n; i++){

        for(ll j=0; j<3; j++){

            if(j==0){
                dp[i][j] = arr[i].A + max(dp[i-1][1], dp[i-1][2]);
            }
            else if(j==1){
                dp[i][j] = arr[i].B + max(dp[i-1][0], dp[i-1][2]);
            }
            else if(j==2){
                dp[i][j] = arr[i].C + max(dp[i-1][1], dp[i-1][0]);
            }
        }
    }

    ll ans = INT_MIN;
   for(ll i=0; i<3; i++){
    ans = max(ans, dp[n-1][i]);
   }

   cout << ans;
}
#include <bits/stdc++.h>

#define ll long long
#define ss second
#define ff first
#define pb push_back

using namespace std;

const int N = 1e6 + 69;

int n;
ll A[20][20], cost[(1<<20)], dp[(1<<20)];

int main(){

        cin >> n;
        for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                        cin >> A[i][j];
                }
        }

        for(int mask = 0; mask < (1 << n); mask++){
                for(int i = 0; i < n; i++){
                        for(int j = i + 1; j < n; j++){
                                if((mask&(1<<i)) && (mask&(1<<j)))
                                cost[mask] += A[i][j];
                        }
                }
        }


        for(int mask = (1 << n) - 1; mask > 0; mask--){
                for(int mask1 = mask; mask1 > 0; mask1 = mask&(mask1-1)){
                        dp[mask^mask1] = max(dp[mask^mask1], dp[mask] + cost[mask1]);
                }
        }

        cout << dp[0] << endl;
}

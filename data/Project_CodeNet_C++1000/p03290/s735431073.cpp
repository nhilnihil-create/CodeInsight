#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define f first
#define s second
using namespace std;
int dp[20000001];
int d, g;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> d >> g;
    for(int i = 0; i <= 20000000; i++)dp[i] = 1e9;
    dp[0] = 0;
    for(int i = 1; i <= d; i++){
        int p, c; cin >> p >> c; int foo = i*100;
        for(int j = 15000000; j >= 0; j--){
            if(dp[j] == 1e9)continue;
            for(int k = p; k >= 1; k--){
                if(k == p){
                    if(dp[j]+k < dp[j+foo*k+c])dp[j+foo*k+c] = dp[j]+k;
                    continue;
                }
                if(dp[j]+k < dp[j+foo*k])dp[j+foo*k] = dp[j]+k;
            }
        }
        /*
        for(int i = 0; i <= 20000000; i++){
            if(dp[i] == 1e9)continue;
            cout << i << " " << dp[i] << endl;
        }
        cout << endl;
        */
    }

    int res = 1e9;
    for(int i = g; i <= 20000000; i++)res = min(res, dp[i]);
    cout << res << endl;
    return 0;
}

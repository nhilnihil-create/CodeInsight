#include<bits/stdc++.h>

using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }


const int DIGIT = 50;


int main()
{
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n);
    vector<vector<ll>> dp(100, vector<ll>(2, -1));
    for(int i = 0; i < n; i++)cin >> a[i];
    dp[0][0] = 0;

    for(int d = 0; d < DIGIT; d++){
        ll mask = (1LL << (DIGIT - 1 - d));

        int cnt = 0;
        for(int i = 0; i < n; i++)if(a[i] & mask)cnt++;

        ll cost0 = mask * cnt;
        ll cost1 = mask * (n - cnt);

        if(dp[d][1] != -1){
            chmax(dp[d + 1][1], dp[d][1] + max(cost0, cost1));
        }

        if(dp[d][0] != -1){
            if(k & mask){
                chmax(dp[d + 1][1], dp[d][0] + cost0);
            }
        }

        if(dp[d][0] != -1){
            if(k & mask)chmax(dp[d + 1][0], dp[d][0] + cost1);
            else chmax(dp[d + 1][0], dp[d][0] + cost0);
        }
    }

    cout << max(dp[DIGIT][0], dp[DIGIT][1]) << endl;

}
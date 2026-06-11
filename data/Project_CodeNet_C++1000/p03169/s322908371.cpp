#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
// #define endl "\n"

double recurse(ll a, ll b, ll c, ll n, vector<vector<vector<double>>>& dp) {
    if (a+b+c == 0) {
        return 0; // nothing more needs to be done
    }

    if (dp[a][b][c] > -0.5) {
        return dp[a][b][c];
    }

    double ans = (double)n / (a+b+c); // expected number of steps reqt to pick a sushi plate
    // now it could be any one of them, with a conditional probability

    if (a) {
        ans += recurse(a-1, b, c, n, dp) * (double)a / (a + b + c);
    }
    if (b) {
        ans += recurse(a + 1, b - 1, c, n, dp) * (double)b / (a + b + c);
    }
    if (c) {
        ans += recurse(a, b + 1, c - 1, n, dp) * (double)c / (a + b + c);
    }
    dp[a][b][c] = ans;
    return ans;
}

int main(void) {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    ll n;
    cin >> n;

    vector<ll> count (4);
    for (ll i = 0; i  < n; i++) {
        ll a;
        cin >> a;
        count[a]++;
    }

    vector<vector<vector<double>>> dp (n+1, vector<vector<double>> (n+1, vector<double> (n+1, -1)));
    cout << fixed << setprecision(12) << (double)recurse(count[1], count[2], count[3], n, dp) << endl;;


    
    return 0;
}
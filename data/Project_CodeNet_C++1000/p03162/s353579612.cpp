#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <iomanip>
#include <cmath>

#define vi vector<int>
#define tests int t; cin>>t; while(t--)
#define ll long long
#define vll vector<long long>
#define srt(v) sort(v.begin(), v.end())
#define srtg(v) sort(v.begin(), v.end(), greater<int> ())
#define FOR(k, n) for(int k=0; k<n; k++)



using namespace std;

char nums[10] = { '0','1','2','3','4','5','6','7','8','9' };
char alphsl[26] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
const ll MOD = 1000000007;
char alphs[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };

void solve() {

    int n;
    cin >> n;
    vector<vi> v(n, vector<int>(3, 0));

    for (auto& x : v) cin >> x[0] >> x[1] >> x[2];
    vector<vi> dp(n, vector<int>(3, 0));

    dp[n - 1][0] = v[n - 1][0];
    dp[n - 1][1] = v[n - 1][1];
    dp[n - 1][2] = v[n - 1][2];

    for (int i = n - 2; i >= 0; i--) {
        dp[i][0] = v[i][0] + max(dp[i + 1][1], dp[i + 1][2]);
        dp[i][1] = v[i][1] + max(dp[i + 1][0], dp[i + 1][2]);
        dp[i][2] = v[i][2] + max(dp[i + 1][1], dp[i + 1][0]);
    }

    cout << max(dp[0][0], max(dp[0][1], dp[0][2])) << endl;

}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);


    solve();



    return 0;
}
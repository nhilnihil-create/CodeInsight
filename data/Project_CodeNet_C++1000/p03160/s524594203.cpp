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
    vi v(n);
    for (auto& x : v) cin >> x;
    vi dp(n);
    dp[n - 1] = 0;
    dp[n - 2] = abs(v[n - 1] - v[n - 2]);

    for (int i = n - 3; i >= 0; i--) {
        dp[i] = min(abs(v[i + 1] - v[i]) + dp[i + 1], abs(v[i + 2] - v[i]) + dp[i + 2]);
    }

    cout << dp[0] << endl;
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);


    solve();



    return 0;
}
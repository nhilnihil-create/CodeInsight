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

    int n, k;
    cin >> n>>k;
    vi v(n);
    for (auto& x : v) cin >> x;
    vll dp(n);
    if (k >= n-1) {
        cout << abs(v[0] - v[n - 1]) << endl;
        return;
    }
    for (int i = n - 1; i >= n - k; i--) {
        dp[i] = abs(v[i] - v[n - 1]);
        
    }

    for (int i = n - k-1; i >= 0; i--) {
        ll miny = abs(v[i] - v[i + 1]) + dp[i + 1];
        for (int j = 1; j <= k; j++) {
            miny = min(miny, abs(v[i] - v[i + j]) + dp[i + j]);
        }
        dp[i] = miny;
    }

    cout << dp[0] << endl;
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);


    solve();



    return 0;
}

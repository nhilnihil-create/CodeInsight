#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> ii;

bool comp(pair<ii, int> a, pair<ii, int> b) {
    return a.first.first + a.first.second > b.first.first + b.first.second;
}


int main() {
    int n; cin >> n;

    pair<ii, int> arr[n];

    for(int i = 0; i < n; ++i) {
        int w, s, v; cin >> w >> s >> v;
        arr[i] = pair<ii, int>(ii(w, s), v);
    }
    sort(arr, arr + n, comp);

    vector<long long> dp(20004);


    for(int i = n-1; i >= 0; --i) {

        for(int j = min(arr[i].first.second, 20001 - arr[i].first.first); j >= 0; --j) {

            dp[j + arr[i].first.first] = max(dp[ j + arr[i].first.first] , dp[j] + arr[i].second);
        }
    }

    long long ans = 0;

    for(int i = 0; i <= 20001; ++i) {
        ans = max(ans, dp[i]);
    }
    cout << ans;



}
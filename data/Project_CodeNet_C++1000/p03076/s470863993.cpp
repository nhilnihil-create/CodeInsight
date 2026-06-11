#include "bits/stdc++.h"

using namespace std;

int main() {
    vector<pair<int, int>> X(5);
    int a;
    for(int i = 0; i < 5; ++i)
    {
        cin >> a;
        X[i].first = a % 10 == 0 ? 0 : 10 - a % 10;
        X[i].second = a;
    }
    sort(X.begin(), X.end());

    int ans = X[4].second;
    for(int i = 0; i < 4; ++i)
        ans += X[i].first + X[i].second;
    cout << ans << endl;
}
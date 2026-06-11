#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
using namespace std;
using ll = long long;

int main() {
    vector<int> vec(3);
    int K;
    rep(i, 3) cin >> vec[i];
    cin >> K;
    sort(vec.begin(), vec.end());
    cout << vec[0] + vec[1] + vec[2]*pow(2, K) << endl;
    return 0;
}
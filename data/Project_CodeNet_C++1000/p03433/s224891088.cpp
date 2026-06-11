#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < n; ++i)
typedef long long ll;
using namespace std;
const int INF = 1e9;

int main() {
    int n, k;
    cin >> n >> k;

    if (n % 500 <= k)
        cout << "Yes";
    else
        cout << "No";
    cout << endl;

    return 0;
}

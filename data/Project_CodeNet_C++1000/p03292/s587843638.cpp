#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int a1, a2, a3;
    cin >> a1 >> a2 >> a3;

    cout << max({a1, a2, a3}) - min({a1, a2, a3}) << endl;
    return 0;
}

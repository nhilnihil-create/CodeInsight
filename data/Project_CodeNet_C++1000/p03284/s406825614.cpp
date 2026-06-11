#include <bits/stdc++.h>

#define rep(x, y) for (int i = (x); i < (y); i++)

typedef long long ll;

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    cout << (0 < n % k ? 1 : 0) << endl;

    return 0;
}
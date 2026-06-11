
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m, sum;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> m;
        sum += m - 1;
    }
    cout << sum << endl;
    return 0;
}


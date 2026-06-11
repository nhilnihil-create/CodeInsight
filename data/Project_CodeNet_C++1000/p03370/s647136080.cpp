#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    int n, x; cin >> n >> x;
    int sum = 0;
    int minM = 2147483647;
    for (int i = 0; i < n; i++) {
        int  m; cin >> m;
        sum += m;
        minM = min(minM, m);
    }

    cout << n + (x - sum) / minM << endl;
    return 0;
}
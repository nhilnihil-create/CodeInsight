#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1e18

int main() {
    double n, m, d;
    cin >> n >> m >> d;
    cout << setprecision(10) << (d == 0 ? 1 : 2) * (m - 1) * (n - d) / (n * n) << endl;
    return 0;
}
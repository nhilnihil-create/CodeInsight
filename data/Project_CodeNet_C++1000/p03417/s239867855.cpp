#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;

const int N = 100010;
const double eps = 1e-6;

LL n, m, res;

int main()
{
    cin >> n >> m;
    if(n == 1 || m == 1) cout << max(n * m - 2, 1LL) << endl;
    else if(n == 2 || m == 2) cout << 0 << endl;
    else cout << 1LL * (n - 2) * (m - 2) << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ALL(a) (a).begin(), (a).end()
const ll mod = 1e9 + 7;

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    cout << min(a, b) << " " << max(0, a + b - n) << endl;
    return 0;
}

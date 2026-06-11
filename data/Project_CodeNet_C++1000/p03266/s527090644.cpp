#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;

const int N = 100010;
const double eps = 1e-6;

int n, k;

int main()
{
    cin >> n >> k;
    if(k & 1)
    {
        LL res = n / k;
        cout << res * res * res << endl;
    }
    else
    {
        LL res = n / k;
        LL ans = res;
        if(n % k >= k / 2) ans++;
        cout << res * res * res + ans * ans * ans << endl;
    }
    return 0;
}

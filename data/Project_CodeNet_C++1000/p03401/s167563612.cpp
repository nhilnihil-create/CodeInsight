#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define MAX(a, b) ((a) < (b) ? (b) : (a))

const long long INF = 1LL << 60;
typedef unsigned long long ll;
const long long MOD = 1000000000 + 7;

int main()
{
    int n;
    cin >> n;
    vector<int> surplus(n, 0);
    int a[n + 1];
    rep(i, n) cin >> a[i];
    a[n] = 0;
    ll cnt_sum = 0;
    int npos = 0;
    rep(i, n)
    {
        cnt_sum += abs(a[i] - npos);
        if (a[i] < npos && a[i] < a[i + 1])
        {
            surplus[i] = (min(npos, a[i + 1]) - a[i]) * 2;
        }
        if (a[i] > npos && a[i] > a[i + 1])
        {
            surplus[i] = (a[i] - max(npos, a[i + 1])) * 2;
        }
        npos = a[i];
    }
    cnt_sum += abs(a[n - 1]);
    rep(i, n)
    {
        cout << cnt_sum - surplus[i] << endl;
    }
    return 0;
}
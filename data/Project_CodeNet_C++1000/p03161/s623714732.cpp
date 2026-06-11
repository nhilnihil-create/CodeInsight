#include <iostream>
#include <algorithm>
#include <climits>
#define ll long long

using namespace std;

const int NMAX = 100005;
ll h[NMAX], d[NMAX];
ll poz, n, k;

int main()
{
    int i;
    cin >> n >> k >> h[1]; h[0] = INT_MAX;
    for(i = 2; i <= n; i++) {
        cin >> h[i];
        d[i] = INT_MAX;
        int ok = 0;
        for(int j = 1; j <= k && i >= j; j++) {
            int x = abs(h[i] - h[i - j]);
            d[i] = min(d[i], d[i - j] + x);
        }
    }
    cout << d[n];
    return 0;
}

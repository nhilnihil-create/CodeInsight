#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, x;
    int summ = 0;
    int sm = 1e9 + 7;
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        summ += m;
        sm = min(sm, m);
    }
    x -= summ;
    int ans = n + (x/sm);
    cout << ans << endl;
    return 0;
}
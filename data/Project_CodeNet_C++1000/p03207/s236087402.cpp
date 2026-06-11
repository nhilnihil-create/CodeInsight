#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int mx = -1e9, sum = 0;
    for(int i = 0; i < n; i++)
    {
        int p;
        cin >> p;
        mx = max(mx, p);
        sum += p;
    }
    sum -= mx / 2;

    cout << sum;

    return 0;
}

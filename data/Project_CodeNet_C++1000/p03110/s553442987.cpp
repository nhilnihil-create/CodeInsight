#include <bits/stdc++.h>

using namespace std;

const int N = 11;
int n;
long double x[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> x[i];
        string u;
        cin >> u;
        if(u == "BTC")
            x[i] *= 380000;
    }

    long double ans = 0;
    for(int i = 0; i < n; i++)
        ans += x[i];

    cout << fixed << setprecision(10) << ans;

    return 0;
}

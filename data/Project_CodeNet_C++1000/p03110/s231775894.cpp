#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin >> N;
    double ans = 0.0;
    for (int i = 0; i < N; i++)
    {
        double x;
        string u;
        cin >> x >> u;
        if (u == "BTC")
        {
            ans += x * 380000.0;
        }
        else
        {
            ans += x;
        }
    }
    cout << setprecision(15) << fixed << ans << endl;
}
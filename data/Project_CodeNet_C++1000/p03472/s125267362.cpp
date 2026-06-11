#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n, h;
    cin >> n >> h;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
    }

    sort(a.begin(), a.end());
    int maxa = a[n - 1];
    sort(b.begin(), b.end());
    int current = n - 1, ans = 0;
    while (h > 0)
    {
        if (current < 0 || maxa >= b[current])
        {
            ans += h / maxa + (h % maxa != 0);
            h = 0;
            break;
        }
        else
        {
            h -= b[current];
            current -= 1;
            ans++;
        }
    }
    cout << ans << endl;
}

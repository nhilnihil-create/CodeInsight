#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void)
{
    int n,d,x;
    cin >> n >> d >> x;
    vector<int> a(n);

    for (int i = 0;i < n;i++) cin >> a[i];

    int ans = x;

    for (int i = 0;i < n;i++)
    {
        for (int day = 1;day <= d;day += a[i])
        {
            ans++;
        }
    }

    cout << ans << endl;
    
    return 0;
}

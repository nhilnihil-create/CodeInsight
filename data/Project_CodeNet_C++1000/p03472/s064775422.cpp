#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,h;
    cin >> n >> h;
    vector<int> a(n),b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
    }
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int maxa = a[n - 1];
    long long ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if(b[i] > maxa)
        {
            h -= b[i];
            ans++;
        }
        else
        {
            break;
        }
        if(h <= 0)break;
    }

    if(h > 0)ans += (h + maxa - 1) / maxa;

    cout << ans << endl;
}
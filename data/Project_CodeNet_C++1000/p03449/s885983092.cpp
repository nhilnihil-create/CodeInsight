#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a1(n), a2(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a1[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> a2[i];
    }

    vector<int> cum1(n + 1, 0), cum2(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        cum1[i + 1] = cum1[i] + a1[i];
        cum2[i + 1] = cum2[i] + a2[i];
    }
    
    int ans = 0;
    for (int i = 1; i < n + 1; i++)
    {
        ans = max(ans, cum1[i] + cum2[n] - cum2[i - 1]);
    }
    cout << ans << endl;
}

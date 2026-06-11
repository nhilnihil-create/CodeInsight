#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> po;
    vector<int> ne;
    po.push_back(0);
    ne.push_back(0);
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        if (t >= 0)
            po.push_back(t);
        else
            ne.push_back(-t);
    }
    sort(ne.begin(), ne.end());
    sort(po.begin(), po.end());
    int ans = 0x3f3f3f3f;

    for (int i = max(0, k - (int)po.size() + 1); (i < (int)ne.size() && i <= k); i++)
    {
        if (ne[i] + po[k - i] + min(ne[i], po[k - i]) < ans)
            ans = ne[i] + po[k - i] + min(ne[i], po[k - i]);
    }
    cout << ans << endl;
}

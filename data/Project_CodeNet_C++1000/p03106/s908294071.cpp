#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (int i = a; i < b; i++)

int main()
{
    int a, b, k;
    cin >> a >> b >> k;
    vector<int> ans;
    if (a > b)
    {
        swap(a, b);
    }
    rep(i, 1, a + 1)
    {
        if (a % i == 0 && b % i == 0)
        {
            // cout << i << endl;
            ans.push_back(i);
        }
    }
    cout << ans[ans.size() - k] << endl;
    return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main()
{
    ll n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int min = *min_element(a.begin(), a.end());
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > min)
        {
            cnt++;
        }
    }
    // cout << cnt << endl;
    int ans;
    if (cnt % (k - 1) == 0)
    {
        ans = cnt / (k - 1);
    }
    else
    {
        ans = cnt / (k - 1) + 1;
    }

    cout << ans << endl;
    return 0;
}

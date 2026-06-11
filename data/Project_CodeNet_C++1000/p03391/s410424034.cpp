#include <iostream>
#include <vector>

using namespace std;

#define int long long

int a[500000], b[500000], sa, t, ans;

signed main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
    	cin >> a[i] >> b[i];
    	sa += a[i];
    	if (a[i] != b[i]) t = 1;
    }
    for (int i = 0; i < n; i++)
    {
    	if (a[i] > b[i])
    	{
    		ans = max(ans, sa - b[i]);
    	}
    }
    cout << ans;
}

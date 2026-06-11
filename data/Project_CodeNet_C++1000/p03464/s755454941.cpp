#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <vector>
#include <tuple>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <math.h>
#include <bitset>
#include <numeric>
#include <stack>
#include <cmath>
#include <queue>
#include <functional>
#include <complex>
#include <cstring>
#include <stdlib.h>
using namespace std;
#define endl '\n'
// #define exp 2.7182818284590452353602874713527
// #define pi acos(-1)
// typedef complex<double> comp;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/detail/standard_policies.hpp>
// using namespace __gnu_pbds;
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define int long long
void solve()
{
	int k;
	cin >> k;
	int mi = 2, ma = 2;
	vector<int> a(k);
	for(auto &i : a)
		cin >> i;
	for(int i = k-1;i >= 0;i--)
	{
		if(mi > (ma/a[i])*a[i])
		{
			cout << -1;
			return;
		}
		mi = a[i]*((int)(ceill(((long double)mi)/a[i])));
		ma = a[i]*(ma/a[i]) + a[i]-1;
	}
	cout << mi << ' ' << ma;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    double t1 = clock();
    int t;
    t = 1;
    // scanf("%d", &t);
    // cin >> t;
    // while(t--)
    for(int i = 1;i <= t;i++)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
    cerr << setprecision(10) << (clock()-t1)/CLOCKS_PER_SEC << "\n";
    return 0;
}
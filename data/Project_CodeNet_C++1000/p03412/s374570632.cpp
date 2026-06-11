// Sky's the limit :)
#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 4e5 + 5;
int n;
int a[N], b[N], c[N];

bool solve(int k) {
	int x = (1 << k);
	for(int i = 0; i < n; i++)
		c[i] = b[i] % (2 * x);
	sort(c, c + n);

	bool f = 0;
	for(int i = 0; i < n; i++)
    {
        int y = a[i] % (2 * x);
        int l = lower_bound(c, c + n, x - y) - c;
        int r = lower_bound(c, c + n, 2 * x - y) - c - 1;

        if(l <= r)
            f ^= (r - l + 1) & 1;

        l = lower_bound(c, c + n, 3 * x - y) - c;
        r = lower_bound(c, c + n, 4 * x - y) - c - 1;
        if(l <= r)
            f ^= (r - l + 1) & 1;
    }
	return f;
}

signed main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    //int t = 1; cin >> t; while(t--)
    {
    	cin >> n;
    	for(int i = 0; i < n; i++)
    		cin >> a[i];
    	for(int i = 0; i < n; i++)
    		cin >> b[i];

    	int ans = 0;
    	for(int i = 0; i < 30; i++) {
    		if(solve(i))
    			ans |= (1 << i);
    	}

    	cout << ans << '\n';

    }
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
    return 0;
}


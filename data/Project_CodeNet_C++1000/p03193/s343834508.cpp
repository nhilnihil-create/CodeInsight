#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define inf 1e18
#define mod pow(10,9)+7
#define mii map<int,int>
#define pii pair<int,int>
#define setbits(x) __builtin_popcountll(x)
// void c_p_c()
// {
// 	ios_base::sync_with_stdio(0);
// 	cin.tie(0);
// 	cout.tie(0);
// // #ifndef  ONLINE_JUDGE
// // 	freopen("input.txt", "r", stdin);
// // 	freopen("output.txt", "w", stdout);
// // #endif
// }
int32_t main()
{
	//c_p_c();
	int n, h, w;
	cin >> n >> h >> w;
	int c = 0;
	while (n--)
	{
		int x, y;
		cin >> x >> y;

		if (x >= h && y >= w)
			c++;
	}
	cout << c << endl;

	return 0;
}
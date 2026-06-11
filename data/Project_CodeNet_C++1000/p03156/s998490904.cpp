/**
 *    author:  whohet
 *    created: 11-07-2020 17:00:37
**/

#include<bits/stdc++.h>
#define fasterthanlight ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define test int T; cin>>T; while(T--)
#define endl "\n"
#define int long long
#define vi vector<int>
#define pb push_back
#define mod 1000000007
#define MAX 1e9
#define MIN -1e9
#define hi "visited\n" //sasta debugging
using namespace std;

signed main()
{
	fasterthanlight;
	int n;
	cin >> n; int a, b;
	cin >> a >> b;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);

	int x = 0, y = 0, z = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] <= a)
			x++;
		else if (arr[i] <= b)
			y++;
		else
			z++;
	}
	y = min(y, z);
	cout << min(x, y);



	//cout << "\n\n"<<"Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " seconds.\n";
	return 0;
}

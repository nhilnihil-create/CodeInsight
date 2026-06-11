#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef struct _data {
	int x;
	int y;
} data;

int  main()
{
	int n, m,x;
	cin >> n >> m >> x;
	set <int> st;
	rep(i , m)
	{
		int a;
		cin >> a;
		st.insert(a);
	}
	int right = 0,left = 0;
	for (int i = x+1; i < n; i++)
	{
		if (st.count(i))
			right++;
	}
	for (int i = x-1; i > 0; i--)
	{
		if (st.count(i))
			left++;
	}
	cout << min(left, right) << endl;
	return (0);
}

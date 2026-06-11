#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
using namespace std;
using P = pair<int,int>;
typedef long long ll;

int  main()
{
	int a,b,k; cin >> a >> b >> k;
	set<int> st;
	for(int i = a; i <= b; i++)
	{
		if (i < a + k)
		{
			cout << i << endl;
			st.insert(i);
		}
	}
	for (int j = b - k; j <= b; j++)
	{
		if (!st.count(j) && j > b - k)
		{
			if (j >= a && j <= b)
				cout << j << endl;
		}
	}
	return (0);
}

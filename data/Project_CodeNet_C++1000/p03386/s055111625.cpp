#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, b, k;
	cin >> a >> b >> k;

	set<int> st;

	for (int i = a; i < min(a + k, b + 1); i++)
	{
		st.insert(i);
	}
	for (int i = b; max(a - 1, b - k) < i; i--)
	{
		st.insert(i);
	}

	for (auto &&x : st)
	{
		cout << x << endl;
	}

	return 0;
}
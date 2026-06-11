#include "bits/stdc++.h"

using namespace std;

void solve()
{
	string S;
	cin >> S;
	vector<int> as(3);
	for (char c : S)
	{
		as[c-'a']++;
	}
	sort(as.begin(), as.end());
	int x = as[1]-as[0], y = as[2]-as[0];
	if ((x == y && x == 1) || (x == 0 && y == 1) || (x == y && y == 0))
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
}

int main(void)
{
	solve();
	//cout << "yui(*-v・)yui" << endl;
	return 0;
}

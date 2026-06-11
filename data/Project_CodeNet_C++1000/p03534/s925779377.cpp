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
	cout << (as[2]-as[0] < 2 ? "YES" : "NO") << endl;
}

int main(void)
{
	solve();
	//cout << "yui(*-v・)yui" << endl;
	return 0;
}

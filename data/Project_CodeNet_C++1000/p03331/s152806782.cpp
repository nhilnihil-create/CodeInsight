#include<bits/stdc++.h>
using namespace std;


int main()
{
	string n; cin >> n;
	int ans = 0;
	for (int i = 0; i < n.size(); ++i)
		ans += n[i] - 48;
	if (ans == 1) ans = 10;
	cout << ans << endl;
}


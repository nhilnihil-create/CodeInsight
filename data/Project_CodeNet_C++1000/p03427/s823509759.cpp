#include<bits/stdc++.h>
using namespace std;
int main() {
	string n; cin >> n;
	int res;
	bool nine = true;
	for (int i = 1; i < n.size(); i++)
	{
		if(n[i] != '9') nine = false;
	}

	if(n.size() == 1) res = n[0] - '0';
	else if(nine) res = 9 * (n.size() - 1) + n[0] - '0';
	else res = 9 * (n.size() - 1) + n[0] - '1';
	cout << res << endl;
	return 0;
}

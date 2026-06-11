#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
	int n; cin >> n;
	vector<string> ss(n); for(int i = 0; i < n; i++)cin >> ss[i];
	int cnt = 0;
	int frb = 0, bca = 0;
	int flag = 0;

	for(int i = 0; i < n; i++) {
		frb += ss[i].front() == 'B';
		bca += ss[i].back() == 'A';
		if(ss[i].front() == 'B' && ss[i].back() != 'A')flag |= 1;
		if(ss[i].back() == 'A' && ss[i].front() != 'B')flag |= 2;

		int n = ss[i].size();
		for(int j = 1; j < n; j++) {
			if(ss[i][j - 1] == 'A' && ss[i][j] == 'B')cnt++;
		}
	}

	cerr << frb << " : " << bca << " :: " << cnt << endl;
	cout << cnt + max(min(frb, bca) - (flag == 0), 0) << endl;

}
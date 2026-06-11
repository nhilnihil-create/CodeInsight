#include<bits/stdc++.h>
using namespace std;
int main() {
	string s; cin >> s;
	int cnt = 0;
	vector<long long> w;
	for (int i = 0; i < s.size(); i++)
	{
		if(s[i] == 'W') {
			w.push_back(i - cnt);
			cnt++;
		}
	}

	long long res = 0;
	for (auto p : w)
	{
		res += p;
	}

	cout << res << endl;
	return 0;
}

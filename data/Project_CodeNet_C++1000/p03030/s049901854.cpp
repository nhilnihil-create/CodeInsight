#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
using namespace std;
using tsii = tuple<string, int , int>;

int main()
{
	int n;
	cin >> n;
	string s;
	int k;
	vector<tsii> v;
	rep(i, n)
	{
		cin >> s >> k;
		tsii t(s, 100 - k, i+1);
		v.push_back(t);
	}
	sort(v.begin(), v.end());
	for (auto x : v)
		cout << get<2>(x) << endl;
}

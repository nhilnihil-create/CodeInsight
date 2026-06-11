#include"bits/stdc++.h"
using namespace std;

int main() {
	int N; cin >> N;
	vector<tuple<string, int, int>> a;
	for (int i = 0; i < N; i++)
	{
		string s; int p;
		cin >> s >> p;
		a.push_back(make_tuple(s, p * -1, i));
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < N; i++)
	{
		int n; tie(ignore, ignore, n) = a.at(i);
		cout << n+1 << endl;
	}
}
#include"bits/stdc++.h"
using namespace std;

int main() {
	int N; cin >> N;
	vector<tuple<string, int, int>> gb;
	for (int i = 0; i < N; i++)
	{
		string a;
		int b;
		cin >> a >> b;
		gb.push_back(make_tuple(a, -1*b, i));
	}
	sort(gb.begin(), gb.end());
	for (int i = 0; i < N; i++)
	{
		int a;
		tie(ignore, ignore, a) = gb.at(i);
		cout << a+1 << endl;
	}
}
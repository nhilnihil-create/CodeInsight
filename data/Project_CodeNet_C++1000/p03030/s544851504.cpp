#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<string>
using namespace std;
int main() {
		int n;
		cin >> n;
		pair<pair<string, int>, int> x[101];
		for(int i = 0; i < n;++i) {
			string s;
			int p;
			cin >> s >> p;
			p *= -1;
			x[i] = make_pair(make_pair(s, p), i + 1);
		}
		sort(x, x + n);
		for(int i = 0; i < n; ++i)
			cout << x[i].second << endl;
}
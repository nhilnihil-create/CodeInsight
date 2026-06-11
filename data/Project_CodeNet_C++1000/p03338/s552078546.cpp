#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<iomanip>
#include<map>
#define ran(x) (x).begin(),(x).end()
using namespace std;
int main() {
	int n, ans = 0;
	string s;
	cin >> n >> s;
	for(int i = 0; i < n; ++i) {
		map<char, pair<int, int>> a;
		for(int j = 0; j < i; ++j) {
			a[s[j]].first = 1;
		}
		for(int j = i; j < n; ++j) {
			a[s[j]].second = 1;
		}
		int cou = 0;
		for(auto i : a) {
			if(i.second.first + i.second.second == 2)
				++cou;
		}
		ans = max(ans, cou);
	}
	cout << ans << endl;
}
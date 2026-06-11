#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

const int N = 100 * 1000 + 5;

map <long long, int> mp;
vector <pair <int, int> > e;
pair <long long, int> d[N];
int c[N];
long long sum[N];


int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> d[i].first;
		d[i].second = i;
		c[i] = 1;
	}
	sort(d + 1, d + n + 1);
	for (int i = 1; i <= n; i++) {
		mp[d[i].first] = i;
	}
	for (int i = n; i > 1; i--) {
		int u = mp[d[i].first - n + 2 * c[i]];
	//	cout << "73 " << d[i].second << " " << d[u].second << endl;
		if (u == 0 || u == i) {
			cout << -1;
			return 0;
		} 
		c[u] += c[i];
		sum[u] += c[i] + sum[i];
		e.push_back({d[i].second, d[u].second});
	}
	if (sum[1] != d[1].first) {
		cout << -1;
		return 0;
	} 
	for (auto p : e) {
		cout << p.first << " " << p.second << endl;
	}
}

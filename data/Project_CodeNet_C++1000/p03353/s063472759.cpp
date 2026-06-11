#define rep(i, n) for(ll i = 0; i < n; i++)
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
	string s;
	int k;
	cin >> s >> k;
	int n = s.size();
	vector<string> bubun;
	for (int i=0;i<n;i++) {
		for (int j=1;(i+j<=n)&&(j<=k);j++) {
			string b = s.substr(i,j);
			bubun.push_back(b);
		}
	}
	sort(bubun.begin(), bubun.end());
	bubun.erase(unique(bubun.begin(), bubun.end()), bubun.end());
	cout << bubun[k-1] << endl;
	return 0;
}

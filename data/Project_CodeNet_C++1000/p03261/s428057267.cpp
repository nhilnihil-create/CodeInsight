#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int main() {
  /**
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
  **/
	FIO
	int n; cin >> n;
	vector<string> words;
	for (int i = 0; i < n; i++) {
		string str; cin >> str;
		words.push_back(str);
	}
	vector<string> w = words;
	if (true) {
		sort(words.begin(), words.end());
		for (int i = 0; i < n-1; i++) {
			if (words[i] == words[i+1]) {
				cout << "No" << "\n";
				exit(0);
			}
		}
	}
	string lw = w[0];
    bool ans = true;
	for (int i = 1; i < n; i++) {
		if ((lw != w[i]) && (w[i][0] == lw[lw.size()-1]))
			lw = w[i];
		else {
			ans = false;
			break;
		}
	}
	(ans) ? cout << "Yes" << "\n" : cout << "No" << "\n";
	return 0;
}
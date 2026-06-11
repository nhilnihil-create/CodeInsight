#include <bits/stdc++.h>
using namespace std;
  
#define ll long long
#define all(aaa) aaa.begin(), aaa.end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    string s;
    cin >> s;
    n = s.size();

    for (int i = 1; i <= n - 1; i++) {
    	if (s[i - 1] != s[n - i - 1]) {
    		cout << "-1";
    		return 0;
    	}
    }

    if (s[0] == '0' || s.back() == '1') {
    	cout << "-1";
    	return 0;
    }

    vector<pair<int, int>> v;

    int last = 1, i = 2;

    for (int i = 2; i <= n; i++) {
    	if (s[i - 2] == '1') {
    		v.push_back({last, i});
    		last = i;
    	}
    	else {
    		v.push_back({last, i});
    	}
    }

    for (auto p : v) {
    	cout << p.first << " " << p.second << "\n";
    }

    return 0;   
}
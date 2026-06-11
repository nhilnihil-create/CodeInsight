#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); 
	
	string s;
	cin >> s;
	int a = 0, b = 0, c = 0;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == 'a') a++;
		if(s[i] == 'b') b++;
		if(s[i] == 'c') c++;
	}
	int mi = min({a, b, c});
	if(a - mi <= 1 && b - mi <= 1 && c - mi <= 1) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}


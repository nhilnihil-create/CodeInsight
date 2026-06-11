#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	string s;
	cin >> s;


	int cnt = 0;
	for (int ii = 0; ii < s.size(); ++ii){
		if (s[ii] == 'o'){
			cnt++;
		}
	}	

	int rem = 15 - s.size();

	if (cnt + rem >= 8){
		cout << "YES" << "\n";
	} else {
		cout << "NO" << "\n";		
	}

	return 0;
}

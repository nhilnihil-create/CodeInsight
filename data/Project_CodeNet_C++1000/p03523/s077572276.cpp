#pragma GCC optimize("Ofast", "unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(void){
	vector<string> ok;
	for (int i = 0; i < (1 << 4); ++i){
		string tmp = "";
		if (i & 1) tmp = "A";
		tmp = tmp + "KIH";
		if (i & 2) tmp = tmp + "A";
		tmp = tmp + "B";
		if (i & 4) tmp = tmp + "A";
		tmp = tmp + "R";
		if (i & 8) tmp = tmp + "A";
		ok.push_back(tmp);
	}
	// for (auto s : ok) cout << s << endl;
	
	string S;  cin >> S;
	for (auto s : ok){
		if (S == s){
			cout << "YES" << endl;
			return 0;
		}
	}

	cout << "NO" << endl;

	return 0;
}
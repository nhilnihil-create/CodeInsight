#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	string S;
	bool flag = false;
	cin >> S;
	if (S == "keyence")flag = true;
	for (int i = 0; i < S.size(); i++) {
		for (int j = 0; j < S.size()-i; j++) {
			string s = S;
			s.erase(i, j);
			if (s == "keyence")flag = true;
		}
	}
	if (flag)cout << "YES";
	else cout << "NO";
}
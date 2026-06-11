#include<bits/stdc++.h>
using namespace std;

int f(int m, int a) {
	return m % a;
}

int main() {
	string s; cin >> s;
	long long k; cin >> k;
	int one = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if(s[i] != '1') break;
		one++;
	}
	if(one == s.size()) cout << "1" << endl;
	else if(one >= k) cout << "1" << endl;
	else cout << s[one] << endl;
	return 0;
}

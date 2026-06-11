#include<iostream>
#include<string>
#include<algorithm>	
#include<cmath>
using namespace std;
int main() {
	long long n = 0; string s; cin >> s;
	for (int h = 0; h < s.size(); h++) {
		if (s[h] == 'o') {
			n++;
		}
	}
	if (15 - s.size() + n >= 8) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	cin >> n;
}
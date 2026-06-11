#include<iostream>
#include<string>
#include<algorithm>	
#include<cmath>
using namespace std;
int main() {
	long long n; string s; cin >> s;
	if (s.size() == 3) {
		cout << s[2] << s[1] << s[0] << endl;
	}
	if (s.size() == 2) {
		cout << s[0] << s[1] << endl;
	}
	cin >> n;
}
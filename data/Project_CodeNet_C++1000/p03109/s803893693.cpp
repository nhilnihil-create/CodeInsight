#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include<map>
#include<unordered_map>
#include<queue>
#include<algorithm>
#include<iomanip>
#include<typeinfo>
#include<complex>
using namespace std;
using ll = long long int;
const int mod = 1e9 + 7;
#define rep(i, a, b) for(ll i = a;i < b; i++)
const long double PI = (acos(-1));


int main() {

	string s;
	cin >> s;

	int ans = 0;
	if (s[0] == '1') ans = 1;
	if (s[0] == '2' && s[1] == '0') {
		if (s[2] <= '1' && s[2] <= '9') {
			if (s[5] == '0' && s[6] <= '4') {
					ans = 1;
			}
		}
	}

	if (ans == 0) cout << "TBD" << endl;
	else cout << "Heisei" << endl;

	return 0;
}
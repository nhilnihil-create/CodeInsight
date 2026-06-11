#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll inf = 1000000007;
int main() {
	string s;
	cin >> s;
	ll k;
	cin >> k;
	if (s[0] != '1') {
		cout << s[0] << endl;
	}
	else {
		for (int i = 0; i < s.size(); i++) {
			if (s[i] != '1'&&k>=i+1) {
				cout << s[i] << endl;
				return 0;
			}
		}
		cout << "1" << endl;
	}
	return 0;
}

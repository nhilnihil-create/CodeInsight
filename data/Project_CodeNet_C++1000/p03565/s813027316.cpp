#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<algorithm>
#include<map>
#include<cstdlib>
#include<cmath>
#include<numeric>
#include<iomanip>
#include<functional>
#include<cstdlib>
#include<queue>
#include<deque>
const double PI = acos(-1);
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
using ll =long long;
const int mod = 1000000007;
int ctoi(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	}
	return 0;
}

ll gcd(ll a, ll b) {
	if (a % b == 0) {
		return b;
	}
	else {
		return gcd(b, a % b);
	}
}
ll lcm(ll a, ll b) {
	return a * b / gcd(a, b);
};
//fixed << setprecision(2)
bool  Array_check(ll y, ll x,ll d,ll w) {
	if (x < 0 || x >= w || y<0 || y>=d) {
		return false;
	}
	else {
		return true;
	}
	
}
//小文字=大文字+32
int main() {
	string s;
	string t;
	cin >> s >> t;
	for (int i = s.size() - t.size(); i >= 0;i--) {
		rep(j, t.size()){
			if (t[j] != s[i+j]&&s[i+j]!='?') {
				break;

			}
			if (j+1 == t.size()) {
				rep(k, i) {
					if (s[k] == '?') {
						cout << 'a';
					}
					else {
						cout << s[k];
					}
				}
				cout << t;
				for (int k = i + t.size(); k < s.size(); k++) {
					if (s[k] == '?') {
						cout << 'a';
					}
					else {
						cout << s[k];
					}

				}
				return 0;
			}


		}

	}
	cout << "UNRESTORABLE";

}

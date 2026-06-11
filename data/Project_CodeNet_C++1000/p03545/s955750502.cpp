#include <iostream>
#include <iomanip>
#include<vector>
#include <algorithm>
#include <queue>
#include<string>
#include <map>
#include <cmath>
#include <deque>
#include <list>
#include <stack>
#include <queue>
#include <utility>
#include <set>
#include <bitset>
typedef long long ll;
typedef long double ld;

#define REP(i,s,n)for(ll i=s;i<(n);++i)
#define rep(i,n) REP(i,0,n)
using namespace std;
vector<vector<ll>>A;


int main() {
	string ABCD;
	cin >> ABCD;
	rep(bit,1<<ABCD.length()) {
		vector<ll> vecABCD;
		rep(i,ABCD.length()) {
			if (i==0) {
				vecABCD.push_back(ABCD[i]-'0');
			}
			else if (bit&(1<<i)) {
				vecABCD.push_back(ABCD[i] - '0');
			}
			else {
				vecABCD.push_back((ABCD[i] - '0')*(-1));
			}
		}
		ll tmp = 0;
		rep(i,vecABCD.size()) {
			tmp += vecABCD[i];
		}
		if (tmp==7) {
			A.push_back(vecABCD);
		}
		
	}

	if (0<A.size()) {
		string ans;
		rep(i, A[0].size()) {
			if (i==0) {
				ans = ans + to_string(A[0][i]);
			}
			else if (0<=A[0][i]) {
				ans = ans + "+";
				ans = ans + to_string(A[0][i]);
			}
			else {
				ans = ans + to_string(A[0][i]);
			}
			 if (i == A[0].size() - 1) {
			ans = ans + "=7";
	}
		}
		cout << ans << endl;
	}
	return 0;
}
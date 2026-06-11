#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <bitset>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tl3;



const int BIG_NUM = 1e9;
const ll INF = 1000000000000000000;
const ll MOD = 1e9 + 7;
//const ll MOD = 998244353;

const int MAX = 1e5+5;



int main() {
	int n;
	cin >> n;



	cout << 0 << endl << flush;
	
	string s0;
	cin >> s0;
	if (s0[0] == 'V') {
		
		return 0;
	}

	cout << n - 1 << endl << flush;
	
	string sl;
	cin >> sl;
	if (sl[0] == 'V') {
		
		return 0;
	}

	int l = 0;
	int r = n - 1;


	for (int i = 0; i < 18; i++) {
		int m = (l + r) / 2;
		

		cout << m << endl << flush;
		string s;
		cin >> s;
		if (s[0] == 'V') {
			//cout << m << endl <<  flush;
			return 0;
		}

		if ((s[0] == s0[0]) ^(m %2 == 1)) {
			l = m;
		}
		else {
			r = m;
		}



	}
	
	return 0;

}
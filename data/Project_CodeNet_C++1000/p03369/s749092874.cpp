#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <bitset>
#include<vector>
#include<utility>
#include<fstream>
#include<queue>
#include <iomanip>
#include<numeric>
#include<set>
#include<map>
#include<functional>
using namespace std;
#define rep(i, k) for (i = 0; i < k; i++) 
typedef long long ll;
typedef pair<ll, ll> l_l;
int i, j;

ll b, k, n = 0, z = 0, x, y, p[1010] = {};
	vector<ll> v,vec;
	string s;
int main() {
	cin >> s;
	b = 700;

	rep(i,s.length()) {
		if (s[i] == 'o') {
			b += 100;
		}

	}

	cout << b;
	return 0;

}

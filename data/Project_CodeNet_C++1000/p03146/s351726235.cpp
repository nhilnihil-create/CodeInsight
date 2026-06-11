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

	int s;
	cin >> s;

	map<int, int> m;

	int i = 1;
	m[s] = 1;
	int a = s;

	while (m[a] != 2) {
		i++;
		if (a % 2 == 0) a /= 2;
		else a = 3 * a + 1;
		m[a]++;
	}

	cout << i << endl;

	return 0;
}
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

ll exp(ll);

int main() {

	int a, b;
	cin >> a >> b;

	if (a <= 5) cout << 0 << endl;
	else if (a <= 12) cout << b / 2 << endl;
	else cout << b << endl;

	return 0;
}
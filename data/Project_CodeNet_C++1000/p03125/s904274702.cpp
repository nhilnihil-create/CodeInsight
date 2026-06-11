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

	int a, b;
	cin >> a >> b;

	if (b % a == 0) cout << a + b << endl;
	else cout << b - a << endl;

	return 0;
}
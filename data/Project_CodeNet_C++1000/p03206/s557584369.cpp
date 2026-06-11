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

	int d;
	cin >> d;
	string s = "Christmas", t = "Eve";

	cout << s;
	int n = 25 - d;
	rep(i, 0, n) cout << " " << t;

	cout << endl;

	return 0;
}
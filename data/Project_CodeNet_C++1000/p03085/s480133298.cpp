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

	char b;
	cin >> b;

	if (b == 'A') cout << "T";
	else if (b == 'T') cout << "A";
	else if (b == 'C') cout << "G";
	else cout << "C";

	cout << endl;

	return 0;
}
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

	int k;
	vector<int> a(5);
	
	rep(i, 0, 5) cin >> a[i];
	cin >> k;

	int ans = 0;

	rep(i, 0, 4) {
		rep(j, i, 5) {
			if (a[j] - a[i] > k) ans = 1;
		}
	}

	if (ans == 1) cout << ":(" << endl;
	else cout << "Yay!" << endl;

	return 0;
}
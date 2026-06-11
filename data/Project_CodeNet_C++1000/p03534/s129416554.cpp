#include "bits/stdc++.h"

typedef long long ll;
using namespace std;

const ll MOD = 1e9+7;
const ll INF = 1e18+7;

signed main(){
	string s;
	cin >> s;

	int n = s.size();
	vector<int> v(3);
	v[0] = count(s.begin(), s.end(), 'a');
	v[1] = count(s.begin(), s.end(), 'b');
	v[2] = count(s.begin(), s.end(), 'c');
	sort(v.begin(), v.end(), greater<int>());

	int arr1 = n / 3 + (n % 3 >= 1);
	int arr2 = n / 3 + (n % 3 >= 2);
	int arr3 = n / 3;
	cout << (arr1 > v[0] || arr2 > v[1] || arr3 > v[2] ? "NO" : "YES") << endl;
}

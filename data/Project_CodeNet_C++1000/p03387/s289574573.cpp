#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll inf = 1000000007;
int a[3];
int main() {
	for (int i = 0; i < 3; i++) {
		cin >> a[i];
	}
	ll count = 0;
	while (a[1] != a[2] || (a[1] - a[0]) % 2 != 0) {
		sort(a, a + 3);
		a[0]++;
		a[1]++;
		count++;
		
	}
	cout << count + (a[1] - a[0]) / 2 << endl;
	return 0;
}

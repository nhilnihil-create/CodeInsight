#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll inf = 1000000007;
int a[100005], check[100005];
int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if ((n - k) % (k - 1) != 0) {
		cout << (n - k) / (k - 1) + 2 << endl;
	}
	else {
		cout << (n - k) / (k - 1) + 1 << endl;
	}
	return 0;
}



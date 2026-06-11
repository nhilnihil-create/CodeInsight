#include <bits/stdc++.h>

using namespace std;

#define ll long long

struct Gem {
	int a, b;
};

bool cmp(Gem x, Gem y) {
	return x.a - x.b > y.a - y.b;
}


void solve() {

	int n;
	cin >> n;
	Gem arr[n];
	for(int i = 0; i < n; i++) {
		cin >> arr[i].a;
	}
	for(int i = 0; i < n; i++) {
		cin >> arr[i].b;
	}
	sort(arr, arr + n, cmp);
	ll total = 0;
	for(int i = 0; i < n; i++) {
		if(arr[i].a - arr[i].b < 0) {
			break;
		}
		else {
			total += arr[i].a - arr[i].b;
		}
	}
	cout << total;

	




	
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	solve();

	return 0;
}
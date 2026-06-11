#include <bits/stdc++.h>

#define ll long long int
#define ull unsigned long long int
#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);


using namespace std;

const int INF = 1e9 + 7;
const int N = 1e5+5;

int main() {

	IO; 

	int n;
	cin >> n;
	vector<int> a(n);
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	
	sort(a.begin(), a.end());
	
	for (int i = 0; i < n-1; ++i) {
		cnt += a[i];
	}
	
	if (cnt > a[n-1]) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	
}


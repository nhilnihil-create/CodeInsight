#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define ll long long

int main() {
	int n;
	scanf("%d", &n);
	int arr[n];
	map<int, int> mp;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		mp[arr[i]]++;
	}
	sort(arr , arr+n);
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		if (binary_search(arr, arr + n, num) && mp[num] > 0) {
			mp[num]--;
		} else
			return cout << "NO\n", 0;
	}
	cout << "YES\n";
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define ll long long

int main() {
	int n;
	cin >> n;
	int arr[n];
	unordered_map<int, int> mp;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		mp[arr[i]]++;
	}
	ll ans = 0;
	for (auto i : mp) {
		if (i.first < i.second) ans += i.second - i.first;
		else if(i.first > i.second)
		ans += i.second;
	}
	cout << ans <<endl;
}

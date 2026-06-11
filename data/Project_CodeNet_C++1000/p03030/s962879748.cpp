#include <bits/stdc++.h>

using namespace std;

#define ll long long

struct Restaurant {
	string name;
	int score;
	int id;
};

bool cmp(Restaurant &a, Restaurant &b) {
	if(a.name == b.name) {
		return a.score > b.score;
	}
	return a.name < b.name;
}

void solve() {

	int n;
	cin >> n;
	Restaurant arr[n];
	for(int i = 0; i < n; i++) {
		cin >> arr[i].name >> arr[i].score;
		arr[i].id = i + 1;
	}
	sort(arr, arr + n, cmp);

	for(int i = 0; i < n; i++) { 
		cout << arr[i].id << "\n";
	}	




	
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	solve();

	return 0;
}
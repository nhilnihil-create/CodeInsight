// In the name of God

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	vector<int> v(5);
	int k;
	for(int i = 0; i < 5; i++) cin >> v[i];
	cin >> k;
	for(int i = 0; i < 5; i++) {
		for(int j = i + 1; j < 5; j++) {
			if(abs(v[i]-v[j])>k) {
				cout << ":(";
				exit(0);
			}
		}
	}
	cout << "Yay!";
	return 0;
}

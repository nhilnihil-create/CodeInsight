#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int N;
	cin >> N;
	string W[N];
	cin >> W[0];

	for (int i = 1; i < N; i++) {
		cin >> W[i];
		if (W[i-1].back() != W[i].front()) {
			cout << "No" << endl;
			return 0;
		}
		rep(j,i) {
			if (W[i] == W[j]) {
			cout << "No" << endl;
			return 0;
			}
		}
	}
	
	cout << "Yes" << endl;

	return 0;
}

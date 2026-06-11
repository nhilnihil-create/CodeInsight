#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	int N;
	cin >> N;
	vector <int> b(N, 0);
	for (int ii = 0; ii < N; ++ii){
		cin >> b[ii];
		b[ii]--;
	}

	vector <int> ans(N, 0);
	int cnt = 0;
	while(b.size() > 0) {
		bool OK = false;
		for (int ii = b.size() - 1; ii >= 0; --ii){
			if (b[ii] == ii){
				OK = true;
				ans[N - cnt - 1] = ii+1;
				b.erase(b.begin() + ii);
				break;
			}
		}
		if (!OK){
			cout << -1 << endl;
			return 0;
		}
		cnt++;
	}

	for (int ii = 0; ii < N; ++ii){
		cout << ans[ii] << " ";	
	}
	cout << "\n";	

	return 0;
}

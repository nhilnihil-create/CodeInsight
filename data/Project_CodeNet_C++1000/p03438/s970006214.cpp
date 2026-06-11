#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	ll N;
	cin >> N;

	vector <ll> a(N);
	for (int ii = 0; ii < N; ++ii){
		cin >> a[ii];
	}
	vector <ll> b(N);
	for (int ii = 0; ii < N; ++ii){
		cin >> b[ii];
	}

	ll opNumA = 0;
	ll opNumB = 0;
	for (int ii = 0; ii < N; ++ii){
		if (a[ii] <= b[ii]){
			opNumA += (b[ii] - a[ii]) / 2;
		} else {
			opNumB += a[ii] - b[ii];
		}
	}

	if (opNumA >= opNumB){
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;		
	}


	return 0;
}

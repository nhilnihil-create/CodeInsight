// #include <bits/stdc++.h>
#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#define rep(i,n) for(int i=0;i<n;i++)
#define reps(i,x,n) for(int i=x;i<n;i++)
#define exrep(x,vec) for(auto&& x : vec);
#define PI 3.14159265358979323846264338327950288
const int MOD{ int(1e9 + 7) };	// = 1000000007
const int inf{ 2100000000 };	// = 2100000000 (MAX:2147483647)
typedef long long ll;
using namespace std;

// -------------------------------------------------- //
// ------------------ ここから本編 ------------------ //
// -------------------------------------------------- //

int main(void) {

	int N; cin >> N;
	ll sum = 0;
	ll MIN = inf;
	bool isOdd = false;
	bool isZero = false;
	vector<ll> A(N);
	rep(i, N) {
		cin >> A[i];
		if (A[i] < 0) isOdd = !isOdd;
		if (A[i] == 0) isZero = true;
		sum += abs(A[i]);
		MIN = min(MIN, abs(A[i]));
	}

	if (!isOdd || isZero) {
		cout << sum << endl;
	}
	else {
		cout << sum - MIN * 2 << endl;
	}
	
	return 0;
}

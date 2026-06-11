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
#define breps(i,x,n) for(int i=x;i>=n;i--)
#define exrep(x,vec) for(auto&& x : vec);
#define PI 3.14159265358979323846264338327950288
const int MOD{ int(1e9 + 7) };	// = 1000000007
const int inf{ 2100000000 };	// = 2100000000 (MAX:2147483647)
typedef long long ll;
using namespace std;

// -------------------------------------------------- //
// ------------------ ここから本編 ------------------ //
// -------------------------------------------------- //

ll flag(ll x) {
	ll F;
	if (x % 2 == 0) {
		if (x / 2 % 2 == 0) F = 0 ^ x;
		else F = 1 ^ x;
	}
	else {
		ll xx = x - 1;
		if (xx / 2 % 2 == 0) F = 0 ^ x ^ xx;
		else F = 1 ^ x ^ xx;
	}
	return F;
}

int main(void) {

	ll A, B; cin >> A >> B;

	ll Fa = flag(A - 1);
	ll Fb = flag(B);

	cout << (Fa ^ Fb) << endl;
	return 0;
}

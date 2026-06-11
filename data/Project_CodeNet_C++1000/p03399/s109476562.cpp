#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define pf push_front
#define pp pop
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
typedef long double ld;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int A, B, C, D;
	cin >> A >> B >> C >> D;
	cout << min(A, B) + min(C, D) << '\n';
}

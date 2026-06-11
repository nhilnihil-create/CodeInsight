#include <bits/stdc++.h>
using namespace std;

#define mem( arr, i ) fill( arr, arr + sizeof (arr), i )
#define MEM( arr, i ) memset( arr, i, sizeof (arr) )
#define Push push_back
#define Pair make_pair
typedef unsigned long long ull;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
typedef vector<int> vcI;
typedef vector<lli> vcL;
typedef vector<pii> vPI;
typedef vector<pll> vPL;
//typedef priority_queue<T> prior_S<T>;
//typedef priority_queue< T, vector<T>, greater<T> > prior_B<T>;
const double PI = 3.141592653589793;
const lli I_MAX = 1LL << 60;
const lli mod = 1000000007;


void precal() {

	return;
}

void solve() {
	int n, m;
	cin >> n >> m;
	cout << max( 0, n-m+1 ) << '\n';
}

int main() {
	precal();
	int t = 1;
//	cin >> t;
	for (int i = 1; i <= t; ++i) {
//		printf("Case #%d: ", i );
		solve();
	}
	return 0;
}

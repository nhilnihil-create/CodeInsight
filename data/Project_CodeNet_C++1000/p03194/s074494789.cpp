#include <bits/stdc++.h>
using namespace std;

#define start_routine() int begtime = clock();
#define end_routine() int endtime = clock(); cerr << endl << "Time elapsed: " << (endtime - begtime)*1000/CLOCKS_PER_SEC << " ms"; return 0
#define speed() cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define exit(a, b) return cout << a, b;

#define PB push_back
#define MP make_pair

#define sd(n) scanf("%lld", &n)
#define pdn(n) printf("%lld\n", n);
#define pds(n) printf("%lld ", n);
#define endl '\n'

#define forn(a, b, i) for (int i = a; i < b; i += 1)
#define all(v) v.begin(), v.end() 

using vi = vector<int>;
using vb = vector<bool>;
using pii = pair<int, int>;
using mii = map<int, int>;

#define print(stuff) cout << stuff << endl
#define len(stuff) stuff.size()

#define int long long
#define float long double 

const int upper = 4e5 + 2;
const int M = (int) 1e9 + 7;
const int inf = (int) 1e17;
const double eps =  1e-8;

map<int, int> primecnt;
signed main () {
	start_routine();
	speed();
	#ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);	
	// freopen("output.txt", "w", stdout);
	// freopen("errlog.txt", "w", stderr);
	#endif

	int n, p; cin >> n >> p;
	int mn = inf;

	int te = p;
	vi primes;
	for (int i = 2; i * i <= p; i += 1) {
		int cnt = 0;
		while (te % i == 0) {
			te /= i;
			primecnt[i] += 1;
		}
		if (!cnt) continue;
		mn = min(mn, cnt);
	}
	if (te > 1) {
		primecnt[te] += 1;
		mn = min(mn, 1LL);
	}

	int g = 1;
	for (auto i: primecnt) {
		int kitnibaar = i.second / n;
		for (int j = 0; j < kitnibaar; j += 1) g *= i.first;
	}
	cout << g;
 	end_routine();	
}
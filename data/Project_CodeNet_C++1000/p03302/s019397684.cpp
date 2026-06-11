#include <bits/stdc++.h>
using namespace std;
#define start_routine cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); int begtime = clock();
#define end_routine int endtime = clock(); cerr << endl << "Time elapsed: " << (endtime - begtime)*1000/CLOCKS_PER_SEC << " ms"; return 0
#define contests_de_diya_kar 0
#define PB push_back
#define MP make_pair
#define int long long
#define MOD ((long long) (1000*1000*1000 + 7))
#define inf (int) 2e15
#define exit(a, b) return cout << a, b;
#define eps (double)1e-8
#define forn(a, b, i) for (int i = a; i < b; i += 1)
#define vi vector<int>
#define vb vector<bool>
#define all(v) v.begin(), v.end()
#define ll long long 
#define pii pair<int, int>
#define mii map<int, int> 
#define print(stuff) cout << stuff << endl
#define len(stuff) stuff.size()

signed main () {
	start_routine;
	#ifndef ONLINE_JUDGE
	//freopen("input.txt", "r", stdin);
	#endif

	int a;
	int b;
	cin >> a >> b;

	if (a + b == 15) {
		cout << "+" << endl;
	}
	else if (a * b == 15) {
		cout << "*" << endl;
	}
	else cout << "x" << endl;
	end_routine;
}

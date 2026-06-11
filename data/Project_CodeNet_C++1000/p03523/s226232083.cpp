#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, j, n) for(int i = j; i <= n; ++i)
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl;
#define ios cin.tie(0); ios_base::sync_with_stdio(0)
 
using namespace std;
using namespace __gnu_pbds;
 
// order_of_key
// find_by_order
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ja;
string s;
string wzor = "AKIHABARA";

int main() {				 
	ios;
	cin >> s;
	int n = ss(s);
	int wsk = 0;
	FOR(i, 0, n - 1) {
		if(wsk >= ss(wzor)) {
			cout << "NO";
			return 0;
		}
		if(s[i] == wzor[wsk])
			wsk += 1;
		else if(wzor[wsk] != 'A') {
			cout << "NO";
			return 0;
		}
		else {
			wsk += 1;
			i -= 1;
		}
	}
	
	if(wsk == ss(wzor) || wsk == ss(wzor) - 1)
		cout << "YES";
	else
		cout << "NO";
		
	
	
	return 0;
}
		

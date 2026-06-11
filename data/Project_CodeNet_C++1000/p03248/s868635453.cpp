#pragma comment(linker, "/stack:20000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")

#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

#include <x86intrin.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define all(x) x.begin(), x.end()

#define mp make_pair
#define in insert
#define er erase
#define con continue
#define pb push_back
#define sc scanf
#define pr printf
#define ub upper_bound
#define lb lower_bound
#define s second
#define f first
#define int long long

const long long infl = 1e18; 
const int N = 3e5 + 300, N2 = 2e3, inf = 1e9 + 200;

set <int> S;
vector <int> g;
int n, m, k;
int a[N];
string s;

void bad(){
	cout << -1;
	exit(0);
}

main (){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> s;
	if (s[0] == '0' || s.back() == '1') bad();
	vector <int> v;
	for (int i = 0; i < s.size() - 1; i++){
		if (s[i] != s[s.size() - 2 - i]){
			bad();
		}
		if (s[i] == '1'){
			v.pb(i + 1);
		}
	}
	k = v.size();
	for (int i = 2; i <= k + 1; i++){
		cout << i << " " << i - 1 << endl;
 	}
 	int last = k + 2;
 	for (int i = 2; i <= k; i++){
 		int col = v[i - 1];
 		for (int j = 0; j < col - v[i - 2] - 1; j++){
 			cout << i << " " << last++ << endl;
 		}
 	}
	return 0;
}











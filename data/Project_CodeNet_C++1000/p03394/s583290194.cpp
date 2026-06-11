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
string ss;

int ch(vector <int> &v){
	int sum = 0;
	for (int i = 0; i < n; i++) sum += v[i];
	for (int i = 0; i < n; i++){
		if (__gcd(v[i], sum) == 1) return 0;
	}
	int x = 0;
	for (int i = 0; i < n; i++){
		x = __gcd(x, v[i]);
	}
	if (x == 1) return 1;
	return 0;
}

main (){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	srand(time(0));
	cin >> n;
	/*if (n == 3){
		cout << "2 3 25";
		return 0;
	}*/
	/*if (n == 4){
		cout << "2 3 4 9";
		return 0;
	}*/
	/*if (n == 5){
		cout << "2 3 4 5 16";
		return 0;
	}*/
	vector <int> v;
	for (int i = 2; i <= 30000; i += 2) v.pb(i);
	for (int i = 3; i <= 30000; i += 6) v.pb(i);
	while (!ch(v)) random_shuffle(all(v));
	for (int i = 0; i < n; i++){
		cout << v[i] << " ";
	}
	return 0;
}











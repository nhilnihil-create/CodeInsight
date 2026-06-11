#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset; // order_of_key, find_by_order

int main() {
	 ios::sync_with_stdio(0);
	 cin.tie(0);
	 cout.tie(0);
	 ll a, b, c;
	 cin >> a >> b >> c;
	 cout << b+min(c,a+b+1);
}

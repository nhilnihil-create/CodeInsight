#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define pll pair <ll, ll>
#define pci pair <char, int>
#define pld pair <ld, ld>
#define ppld pair <pld, pld>
#define ppll pair <pll, pll>
#define pldl pair <ld, ll>
#define vll vector <ll>
#define vvll vector <vll>
#define vpll vector <pll>
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define mll map <ll, ll>
#define fastmap gp_hash_table
#define cd complex <double>
#define vcd vector <cd>
#define PI 3.14159265358979
#define ordered_set tree <ll, null_type, less <ll>, rb_tree_tag, tree_order_statistics_node_update>
#pragma 03
using namespace std;
using namespace __gnu_pbds;
vll o;
vpll edges;
void term(){
	cout << -1 << endl; exit(0);
}
int main(){
	string s; cin >> s;
	ll n = s.length();
	for (ll i = 0; i < n; i++) if (s[i] == '1') o.pb(i);
	if (s[0] == '0') term();
	if (s[n - 1] == '1') term();
	for (ll i = 0; i < n - 1; i++){
		if (s[i] != s[n - 2 - i]) term(); 
	}
	ll k = o.size();
	ll cv = k + 1;
	for (ll i = 0; i < k; i++) edges.pb(mp(i, i + 1));
	for (ll i = 1; i < k; i++){
		for (ll j = 0; j < o[i] - o[i - 1] - 1; j++){
			edges.pb(mp(i, cv)); cv++;
		}
	} 
	for (ll i = 0; i < edges.size(); i++) cout << edges[i].fi + 1 << " " << edges[i].se + 1 << endl;
}
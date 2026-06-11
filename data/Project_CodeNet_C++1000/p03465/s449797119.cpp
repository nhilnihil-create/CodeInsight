/*
    JAI JAGANNATH!
*/
//@Author : zanj0
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long int lli;
#define ff              first
#define ss              second
#define pb              push_back
#define mp              make_pair
#define pii             pair<lli,lli>
#define vi              vector<lli>
#define mii             map<lli,lli>
#define pqb             priority_queue<lli>
#define pqs             priority_queue<lli,vi,greater<lli> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            lli x; cin>>x; while(x--)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<lli, null_type, less<lli>, rb_tree_tag, tree_order_statistics_node_update> pbds;
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;

void zanj0()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
const lli N = 2e3 + 10;
bitset < (N * N) / 2 > bs;
void solve() {
	lli n;
	cin >> n;
	lli a;
	lli sum = 0;
	bs[0] = 1;
	for (lli i = 0; i < n; i++) {
		cin >> a;
		sum += a;
		bs |= (bs << a);
	}
	for (lli i = (sum) / 2; i >= 0; i-- ) {
		if (bs[i]) {
			cout << sum - i << endl;
			return;
		}
	}

}
int main()
{
	zanj0();
	solve();
	return 0;
}
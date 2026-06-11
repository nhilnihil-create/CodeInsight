//============================================================================
// Name        : hoba.cpp :)
// Author      : (O_O Diab) (Why_not) (el 3AQ)
// Version     :
// Copyright   : please, Don't touch me :(
// Description : problem in C++
// MAIN IDEA   : combinatorics NCR
//============================================================================
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ld long double
#define rw freopen("graphs_as_a_service.txt","r",stdin),freopen("output.txt","w",stdout);
#define pb push_back
#define F first
#define S second
#define pf push_front
#define lp(i,a,b) for (int i=a;i<=(int)b;++i)
#define lp2(i,a,b) for (int i=a;i>=b;--i)
#define f(x) return cout<<x<<"\n",0
#define pii pair<int,int>
#define pll pair<ll,ll>
#define all(c) c.begin(),c.end()
#define allr(c) c.rbegin(),c.rend()
#define p(x) cout<<#x<<" = { "<<x<<" } \n"
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pii>
#define vll vector<pll>
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define EPS 1e-6
// to convert string to number use int a = stoi(string);
// to convert number to string use string s = to_string(int);
#define FAST ios::sync_with_stdio(0),ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define clr(c,x) memset(c,x,sizeof(c));
using namespace __gnu_pbds;
using namespace std;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int dx[] = { 0, 1, 0, -1, 1, -1, 1, -1 };
const int dy[] = { 1, 0, -1, 0, 1, -1, -1, 1 };
const int N = 2e2 + 10, mod = (int) 1e9 + 7, INF = 0x3f3f3f3f;
vii v, ans;
int main() {
#ifdef ONLINE_JUDGE
	FAST
#endif
	int n;
	cin >> n;
	lp(i,1,n)
	{
		int x;
		cin >> x;
		v.pb( { x, i });
	}
	bool isn = false, isp = false;
	while (!isn && !isp) {
		sort(all(v));
		int x = v[0].F;
		int y = v.back().F;
		if (x <= 0 && y <= 0) {
			isn = true;
			continue;
		}
		if (x >= 0 && y >= 0) {
			isp = true;
			continue;
		}
		if (abs(x) > abs(y)) {
			v.back().F += v[0].F;
			ans.pb( { v[0].S, v.back().S });
		} else {
			v[0].F += v.back().F;
			ans.pb( { v.back().S, v[0].S });
		}
	}
	if (isn) {
		lp2(i,n,2)
			ans.pb( { i, i - 1 });
	} else {
		lp(i,2,n)
			ans.pb( { i - 1, i });
	}
	cout << ans.size() << "\n";
	for (auto u : ans)
		cout << u.F << " " << u.S << "\n";
	return 0;
}
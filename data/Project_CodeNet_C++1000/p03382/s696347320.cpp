/**
 * @jakestrj
 */

#pragma warning(disable:4996)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include "bits/stdc++.h"
using namespace std;
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define f first
#define s second
#define rep(i, j, k) for(int i=(j);i<(k);++i)
#define repi(i, j, k) for(int i=(j);i<=(k);++i)
#define per(i, j, k) for(int i=(j);i>(k);--i)
#define peri(i, j, k) for(int i=(j);i>=(k);--i)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).begin(),(x).end(), greater<int>()
#define mem(a, b) memset(a, (b), sizeof(a))
#define mem2(a, b) memset(a, (b), sizeof(a[0][0])*len(a)*len(a[0]))
#define sz(x) ((int)(x).size())
#define len(x) (int)(sizeof(x)/sizeof(x[0]))
#define endl "\n"
#define INF 1e18
#define EPS 1e-9
#define PI 2*acos(0)
#define MOD 1000000007
typedef long long ll;
typedef long double ld;
typedef tuple<int, int, int> trio;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef map<int,int> mpii;
typedef set<int> si;

struct D {
	void solve(std::istream& cin, std::ostream& cout) {
		int n; cin >> n;
		vi a(n);
		rep(i, 0, n) cin >> a[i];
		sort(all(a));
		ll mx = a[n-1];
		double n_2 = /*(mx%2==0?(mx/2.0):((mx-1)/2.0));*/mx/2.0;
//		cout << ((n_2)) << endl;
		ld minD = 1e9;
		ll R=a[0];
		rep(i, 0, n-1){
			ld dist = abs(n_2 - a[i]);
			if(dist < minD){
				minD = dist;
				R = a[i];
			}
		}
		cout << mx << " " << R << endl;
	}
};


int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	D solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}

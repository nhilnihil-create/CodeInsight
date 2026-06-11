//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2,tune=native")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("trapv")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<ll>;
using vvi = vector<vi>;
using pi = pair<ll, ll>;
const ll mod = 7 * 17 * (1 << 23) + 1;
const ll inf = 1e18 + 69;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() { //DINIC ORZ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin >> n;
	if(n == 3) {
		cout << "2 5 63";
		return 0;
	}
	cout << "2 3 4 9 ";
	n-=4;
	ll X = 15;
	while(X+6<=30000&&n>1) {
		cout << X << " " << X+6 << "\n";
		X+=12;
		n-=2;
	}
	ll z = 6;
	while(z+4<=30000&&n>2) {
		cout << z << " " << z+2 << " " << z+4 << " ";
		z+=6;
		n-=3;
	}
	if(n==1) {
		cout << z;
	} else if(n==2) {
		cout << z+2 << " " << z+4;
	}
}

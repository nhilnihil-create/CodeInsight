#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define sz(v) (int)v.size()

#define MOO(i, a, b) for (int i=a; i<b; i++)
#define M00(i, a) for (int i=0; i<a; i++)
#define MOOd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define M00d(i,a) for (int i = (a)-1; i >= 0; i--)

#define FAST ios::sync_with_stdio(0); cin.tie(0);
#define finish(x) return cout << x << '\n', 0;
#define dbg(x) cerr << ">>> " << #x << " = " << x << "\n";
#define _<< " _ " <<

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ld,ld> pd;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

//a has higher priority than b?
bool compareF(vi a, vi b) {
	return a[0] + a[1] < b[0] + b[1];
}

int main() { FAST
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	int n;
	cin >> n;
	vector<vi> boxes;
	M00(i, n) {
		//weight, strength, val
		int w, s, v;
		vi temp(3);
		cin >> temp[0] >> temp[1] >> temp[2];
		boxes.pb(temp);
	}
	sort(all(boxes), compareF);
	//DP[i] stores best value with weight i
	vll DP(20010, 0);
	M00(i, n) {
		int w = boxes[i][0];
		int s = boxes[i][1];
		int v = boxes[i][2];
		for(int j = 20000; j>= 1; j--) {
			if(0 <= j - w && j - w <= s) DP[j] = max(DP[j], v + DP[j-w]);
		}
	}
	ll ans = 0;
	M00(i, 20001) ans = max(ans, DP[i]);
	finish(ans);
}

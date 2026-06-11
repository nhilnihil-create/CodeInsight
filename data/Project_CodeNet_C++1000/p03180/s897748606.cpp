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

ll score[1<<16];
ll DP[1 << 16];

int main() { FAST
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	int n;
	cin >> n;
	vector<vll> a(n, vll (n));
	M00(i, n) M00(j, n) cin >> a[i][j];
	//2^n * n^2
	M00(i, 1 << n) {
		score[i] = 0;
		M00(j, n) M00(k, n) {
			int temp = (1 << k) + (1 << j);
			if(k < j && ((i & temp) == temp)) score[i] += a[j][k];
		}
		//dbg(i _ score[i]);
	}
	//DP
	M00(i, 1 << n) {
		//iterate through submasks
		int j = i;
		DP[i] = 0;
		while(j > 0) {
			DP[i] = max(DP[i], score[j] + DP[i ^ j]);
			j--;
			j &= i;
		}
	}
	cout << DP[(1 << n) - 1] << endl;
}

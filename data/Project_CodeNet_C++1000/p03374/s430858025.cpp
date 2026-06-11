#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define int ll

#define rep(i, a) for (int i = 0; (i) < (int) (a); (i)++)
#define reps(i, a, b) for (int i = (int) (a); (i) < (int) (b); (i)++)
#define rrep(i, a) for (int i = (int) a-1; (i) >= 0; (i)--)
#define rreps(i, a, b) for (int i = (int) (a)-1; (i) >= (int) (b); (i)--)
#define MP(a, b) make_pair((a), (b))
#define PB(a) push_back((a))
#define all(v) (v).begin(), (v).end()
#define PERM(v) next_permutation(all(v))
#define UNIQUE(v) sort(all(v));(v).erase(unique(all(v)), v.end())
#define CIN(type, x) type x;cin >> x
#define TRUE__  "Yes"
#define FALSE__ "No"
#define PRINT(f) if((f)){cout << (TRUE__) << endl;}else{cout << FALSE__ << endl;}
#define RS resize
#define CINV(v, N) do {\
	v.RS(N);\
	rep(i, N) cin >> v[i];\
} while (0);
#define RCINV(v, N) do {\
	v.RS(N);\
	rrep(i, N) cin >> v[i];\
} while (0);

#define MOD 1000000007

template<class T>
inline T GET() {
	T x;
	cin >> x;
	return x;
}

void init();
void solve();

signed main()
{
	init();
	solve();
}

ll N, C;
vector<ll>  x, v, xr, vr;
int r1, r2, l1, l2;

void init()
{
	cin >> N >> C;
	rep(i, N) {
		x.PB(GET<ll>());
		v.PB(GET<ll>());
	}
	rrep(i, N) {
		xr.PB(C - x[i]);
		vr.PB(v[i]);
	}
}

void calc(vector<ll>& X, vector<ll>& V, vector<vector<ll>>& score) {
	ll sum = 0;
	score[0][0] = score[1][0] = 0;
	rep(i, N) {
		sum += V[i];
		score[0][i+1] = max(score[0][i], sum - X[i]);
		score[1][i+1] = max(score[1][i], sum - 2 * X[i]);
	}
}

void solve()
{
	vector<vector<vector<ll>>> score;
	score.RS(2, vector<vector<ll>>(2, vector<ll>(N+1, 0)));
	calc(x, v, score[0]);
	calc(xr, vr, score[1]);
	ll res = max(score[1][0][N], score[0][0][N]);
	rep(i, 2) {
		rep(j, 2) {
			rep(k, N+1) {
				cerr << score[i][j][k] << " ";
			}
			cerr << endl;
		}
		cerr << endl;
	}
	reps(i, 1, N) {
		res = max(res, score[0][0][i] + score[1][1][N-i]);
		res = max(res, score[0][1][i] + score[1][0][N-i]);
	}
	cout << res << endl;
}




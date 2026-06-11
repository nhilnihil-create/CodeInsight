// #define _GLIBCXX_DEBUG
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
using ll = long long; using pii = pair<int, int>; using vi = vector<int>; using vvi = vector<vi>; using vl = vector<ll>; using vvl = vector<vl>; using vb = vector<bool>; using vvb = vector<vb>;
#define rep0(TMS) for (int CNT = 0; CNT < (int)(TMS); CNT++)
#define rep(CNT, GOAL) for (int CNT = 0; CNT < (int)(GOAL); CNT++)
#define rep2(CNT, START, GOAL) for (int CNT = (int)(START); CNT < (int)(GOAL); CNT++)
#define rep3(CNT, START, GOAL) for (int CNT = (int)(START); CNT > (int)(GOAL); CNT--)
#define all(CONT) begin(CONT), end(CONT)
template <typename T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template <typename T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }
void prec(const int &DIG) { cout << fixed << setprecision(DIG); cerr << fixed << setprecision(DIG); }
template <typename T> void CERR(const T &ELEM) { cerr << ELEM; }
template <typename T, typename ...Ts> void CERR(const T &FIRST, const Ts &...REST) { CERR(FIRST); cerr << ", "; CERR(REST...); }
#define dbl(OBJ) cerr << #OBJ << ": "; CERR(OBJ); cerr << "\n"
#define dbs(...) cerr << "(" << #__VA_ARGS__ << "): ("; CERR(__VA_ARGS__); cerr << ")\n"
#define itrep(ITR, CONT) for (auto ITR = begin(CONT); ITR != end(CONT); ITR++)
template <typename T> void CERR(const vector<T> &VEC) { cerr << "{ "; itrep(ITR, VEC) { CERR(*ITR); cerr << ", "; } cerr << "}"; }
#define YN(FLG) cout << (FLG ? "YES" : "NO") << "\n"
#define Yn(FLG) cout << (FLG ? "Yes" : "No") << "\n"
#define yn(FLG) cout << (FLG ? "yes" : "no") << "\n"
// const ll INF = LONG_LONG_MAX;
const int INF = INT_MAX;
const ll MOD = 1'000'000'007; // 998'244'353;

// #include <atcoder/all>
// using namespace atcoder;

int main() {
	// 0-ind
	prec(2);
	int N; cin >> N;
	vi t(N); rep(i, N) cin >> t[i];
	vi v(N); rep(i, N) cin >> v[i];

	int T = accumulate(all(t), 0);
	vi V(T); // V[i]:時刻i~i+1に出すことのできる速度
	int cur = 0;
	rep(i, N) {
		rep0(t[i]) {
			V[cur] = v[i];
			cur++;
		}
	}
	// dbl(V);
	vi M(T + 1, INF); // M[i]:時刻T[i]において出すことのできる最大の速度
	cur = 0;
	rep(i, N) {
		chmin(M[cur], v[i]);
		rep0(t[i]) {
			cur++;
			chmin(M[cur], v[i]);
		}
	}
	// dbl(M);
	M[0] = 0;
	rep2(cur, 1, T) chmin(M[cur], M[cur - 1] + 1);
	M[T] = 0;
	rep3(cur, T - 1, 0) chmin(M[cur], M[cur + 1] + 1);
	// dbl(M);

	float ans = 0.0;
	rep(cur, T) {
		if (M[cur] != M[cur + 1]) {
			ans += (M[cur] + M[cur + 1]) / 2.0f;
		} else {
			if (M[cur] < V[cur]) {
				ans += M[cur] + 0.25f;
			} else {
				ans += M[cur];
			}
		}
	}

	cout << ans << endl;
}
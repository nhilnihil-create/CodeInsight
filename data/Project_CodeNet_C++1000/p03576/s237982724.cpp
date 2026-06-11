#define _GLIBCXX_DEBUG
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std; using ll = long long; using pii = pair<int, int>; using vi = vector<int>; using vvi = vector<vi>;
#define rep0(TMS) for (int CNT = 0; CNT < (int)(TMS); CNT++)
#define rep(CNT, GOAL) for (int CNT = 0; CNT < (int)(GOAL); CNT++)
#define rep2(CNT, START, GOAL) for (int CNT = (int)(START); CNT < (int)(GOAL); CNT++)
#define rep3(CNT, START, GOAL) for (int CNT = (int)(START); CNT > (int)(GOAL); CNT--)
#define all(CONT) begin(CONT), end(CONT)
#define itrep(ITR, CONT) for (auto ITR = begin(CONT); ITR != end(CONT); ITR++)
#define itrep1(ITR, CONT) for (auto ITR = next(begin(CONT)); ITR != end(CONT); ITR++)
template <typename T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template <typename T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }
void prec(const int &DIG) { cerr << fixed << setprecision(DIG); cout << fixed << setprecision(DIG); }
template <typename T> void CERR(const T &ELEM) { cerr << ELEM; }
template <typename T, typename ...Ts> void CERR(const T &FIRST, const Ts &...REST) { CERR(FIRST); cerr << ", "; CERR(REST...); }
template <typename T1, typename T2> void CERR(const pair<T1, T2> &PAIR) { cerr << "("; CERR(PAIR.first); cerr << ", "; CERR(PAIR.second); cerr << ")"; }
template <typename T> void CERR(const vector<T> &VEC) { cerr << "{ "; itrep(ITR, VEC) { CERR(*ITR); cerr << ", "; } cerr << "}"; }
template <typename T> void CERR1(const vector<T> &VEC) { cerr << "{ "; itrep1(ITR, VEC) { CERR(*ITR); cerr << ", "; } cerr << "}"; }
template <typename T> void CERR(const set<T> &SET) { cerr << "{ "; itrep(ITR, SET) { CERR(*ITR); cerr << ", "; } cerr << "}"; }
template <typename T> void CERR(const multiset<T> &MULTISET) { cerr << "{ "; itrep(ITR, MULTISET) { CERR(*ITR); cerr << ", "; } cerr << "}"; }
template <typename T1, typename T2> void CERR(const map<T1, T2> &MAP) { cerr << "{ "; itrep(ITR, MAP) { CERR(*ITR); cerr << ", "; } cerr << "}"; }
#define db(OBJ) cerr << #OBJ << ": "; CERR(OBJ); cerr << ", "
#define dbl(OBJ) cerr << #OBJ << ": "; CERR(OBJ); cerr << "\n"
#define db1(OBJ) cerr << #OBJ << ": "; CERR1(OBJ); cerr << "\n"
#define dbs(...) cerr << "(" << #__VA_ARGS__ << "): ("; CERR(__VA_ARGS__); cerr << ")\n"
#define dbvv(VV) cerr << #VV << ": {\n"; rep(CNT, VV.size()) { cerr << #VV << "[" << CNT << "]: "; CERR(VV[CNT]); cerr << ",\n"; } cerr << "}\n"
#define db01(VV) cerr << #VV << ": {\n"; rep(CNT, VV.size()) { cerr << #VV << "[" << CNT << "]: "; CERR1(VV[CNT]); cerr << ",\n"; } cerr << "}\n"
#define db10(VV) cerr << #VV << ": {\n"; rep2(CNT, 1, VV.size()) { cerr << #VV << "[" << CNT << "]: "; CERR(VV[CNT]); cerr << ",\n"; } cerr << "}\n"
#define db11(VV) cerr << #VV << ": {\n"; rep2(CNT, 1, VV.size()) { cerr << #VV << "[" << CNT << "]: "; CERR1(VV[CNT]); cerr << ",\n"; } cerr << "}\n"
#define YN(FLG) cout << (FLG ? "YES" : "NO") << "\n"
#define Yn(FLG) cout << (FLG ? "Yes" : "No") << "\n"
#define yn(FLG) cout << (FLG ? "yes" : "no") << "\n"
const ll INF = 5'000'000'000'000'000'007;
// const int INF = 1'000'000'007;
const ll MOD = 1'000'000'007; // 998'244'353;

int N, K;
vi x, y;
vi i2x, i2y;
map<int, int> x2i, y2i;
vvi g;

/*
int minR(int il, int jd, int ir) {
	int ng = il, ok = N;
	if ((count(il, jd, ir, ok) < K)) return -1;
	while (abs(ok - ng) > 1) {
		int mid = (ng + ok) / 2;
		if (count(il, jd, ir, mid) >= K) ok = mid;
		else ng = mid;
	}
	return ok;
}
ll minsq(int il, int jd, int ir) {
	int ju = minR(il, jd, ir);
	if (ju == -1) return INF;
	else {
		ll width = i2x[ir - 1] - i2x[il];
		ll height = i2y[ju - 1] - i2y[jd];
		return width * height;
	}
}
*/

// [x[il], x[ir]) x [y[jd], y[ju])の点の個数
int count(int il, int jd, int ir, int ju) {
	return g[ir][ju] - g[ir][jd] - g[il][ju] + g[il][jd];
}

int main() {
	// 0-ind
	cin >> N >> K;
	x = y = vi(N);
	i2x = i2y = vi(N);
	rep(i, N) {
		cin >> x[i] >> y[i];
		i2x[i] = x[i]; i2y[i] = y[i];
	}
	sort(all(i2x)); sort(all(i2y));
	rep(i, N) x2i[i2x[i]] = i;
	rep(i, N) y2i[i2y[i]] = i;
	g = vvi(N + 1, vi(N + 1));
	rep(i, N) g[x2i[x[i]] + 1][y2i[y[i]] + 1]++;
	rep2(i, 1, N + 1) rep2(j, 1, N + 1) g[i][j] += g[i][j - 1];
	rep2(i, 1, N + 1) rep2(j, 1, N + 1) g[i][j] += g[i - 1][j];

	ll ans = INF;
	rep(il, N) rep(jd, N) rep2(ir, il + 1, N + 1) rep2(ju, jd + 1, N + 1) {
		// dbs(il, jd, ir, ju); dbl(count(il, jd, ir, ju));
		if (count(il, jd, ir, ju) >= K) {
			ll w = i2x[ir - 1] - i2x[il], h = i2y[ju - 1] - i2y[jd];
			// dbs(il, jd, ir, ju); dbs(w, h, w*h);
			chmin(ans, w * h);
		}
	}
	cout << ans << endl;
}
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

#define MOD 998244353

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

int N, K, Q;
vector<int> A;

#define INF 1123456789


void init()
{
	cin >> N >> K >> Q;
	rep(i, N) A.PB(GET<int>());
}

void add(int x, int& pos, vector<int>& v)
{
	priority_queue<int, vector<int>, greater<int>> q;
	for (; pos < N && A[pos] >= x; pos++) {
		q.push(A[pos]);
	}
	int l = q.size();
	rep(i, l-K+1) {
		v.PB(q.top());
		q.pop();
	}
}

int calc(int x)
{
	vector<int> v;
	for (int pos = 0; pos < N; pos++) {
		while (pos < N && A[pos] < x) pos++;
		add(x, pos, v);
	}
//	rep(i, v.size()) {
//		cout << v[i] << " ";
//	}
//	cout << endl;
	if ((int) v.size() < Q) {
		return INF;
	}
	sort(all(v));
	return v[Q-1] - x;
}

void solve()
{
	int res = INF;
	rep(i, N) {
		res = min(res, calc(A[i]));
	}
	cout << res << endl;
}




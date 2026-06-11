#include <bits/stdc++.h>

using namespace std;
using ll = long long;

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
#define RS(N) resize(N)
#define CINV(v, N) do {\
	v.RS(N);\
	rep(i, N) cin >> v[i];\
} while (0);
#define RCINV(v, N) do {\
	v.RS(N);\
	rrep(i, N) cin >> v[i];\
} while (0);

#define MOD 1000000007

void init();
void solve();

signed main()
{
	init();
	solve();
}

struct syu {
	int k;
	int n;
	vector<vector<int> > v;
};

int N;
vector<syu> ans;

void init()
{
	cin >> N;
	syu s;
	s.k = 1;
	s.v.resize(2, vector<int>(1, 1));
	ans.PB(s);
}

void culc()
{
	auto pre = ans.back();
}

void print(bool f)
{
	if (!f) {
		cout << "No" << endl;
		return;
	}
	auto& res = ans.back();
	cout << "Yes" << endl;
	cout << res.v.size() << endl;
	for (auto x : res.v) {
		cout << x.size();
		for (int y : x) {
			cout << " " << y;
		}
		cout << endl;
	}
}

void mak()
{
	auto ori = ans[ans.size() - 2];
	syu res;
	res.n = ori.n + 2;
	res.v = ori.v;
	int x = ori.k+1;
	for (auto& a : res.v) {
		a.PB(x++);
		a.PB(x++);
	}
	res.v.PB(vector<int>(1, x));
	res.v.PB(vector<int>(1, x));
	int si = res.v.size() - 1;
	reps(y, ori.k+1, x) {
		res.v[si].PB(y);
		y++;
		res.v[si-1].PB(y);
	}
	res.k = x;
	ans.PB(res);
}


void solve()
{
	if (N == 1) {
		print(1);
		return;
	}
	syu s;
	s.k = 3;
	s.n = 2;
	s.v.resize(3);
	s.v[0].PB(1);
	s.v[0].PB(2);
	s.v[1].PB(2);
	s.v[1].PB(3);
	s.v[2].PB(3);
	s.v[2].PB(1);
	ans.PB(s);
	if (N == 2) {
		print(0);
		return;
	}
	if (N == 3) {
		print(1);
		return;
	}
	while(true) {
		if (ans.back().k > N) {
			print(0);
			return;
		} else if (ans.back().k == N) {
			print(1);
			return;
		}
		mak();
	}
}




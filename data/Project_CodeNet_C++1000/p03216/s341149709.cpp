#include <bits/stdc++.h>

using namespace std;
#define ll long long

#define rep(i, a) for (int (i) = 0; (i) < (int) (a); (i)++)
#define reps(i, a, b) for (int (i) = (int) (a); (i) < (int) (b); (i)++)
#define rrep(i, a) for (int (i) = (int) a-1; (i) >= 0; (i)--)
#define rreps(i, a, b) for (int (i) = (int) (a)-1; (i) >= (int) (b); (i)--)
#define MP(a, b) make_pair((a), (b))
#define PB(a) push_back((a))
#define all(v) (v).begin(), (v).end()
#define PRINT(f) if((f)){cout << (TRUE__) << endl;}else{cout << FALSE__ << endl;}
#define TRUE__ "Yes"
#define FALSE__ "No"
#define PERM(v) next_permutation(all(v))
#define UNIQUE(v) sort(all(v));(v).erase(unique(all(v)), v.end())
#define CIN(type, x) type x;cin >> x

void init();
void solve();

signed main()
{
	init();
	solve();
}

int N, Q;
string s;
vector<int> K;

void init()
{
	cin >> N >> s >> Q;
	K.resize(Q);
	rep(i, Q) cin >> K[i];
}

ll calc(int k)
{
	int d = 0, m = 0;
	ll dm = 0;
	int st = 0;
	int en = 1;
	ll res = 0;
	if (s[0] == 'D') d++;
	if (s[0] == 'M') m++;
	while (en < N) {
		if (s[en] == 'C') {
			res += dm;
		} else if (s[en] == 'D') {
			d++;
		} else if (s[en] == 'M') {
			m++;
			dm += d;
		}
		en++;
		st = max(0, en - k + 1);
		if (st) {
			if (s[st-1] == 'D') {
				d--;
				dm -= m;
			} else if (s[st-1] == 'M') {
				m--;
			}
		}
	}
	return res;
}

void solve()
{
	rep(i, Q) {
		cout << calc(K[i]) << endl;
	}
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep2(i, s, n) for (int i = s; i < (int)n; i++)
#define all(obj) obj.begin(), obj.end()
#define debug(x) cerr << #x << ":" << x << "\n"
#define vdebug(vec) cerr << #vec << ":"; for (auto e : vec) cerr << e << " "; cout << "\n"
#define YN(f) cout << (f ? "YES" : "NO") << endl
#define Yn(f) cout << (f ? "Yes" : "No") << endl
#define yn(f) cout << (f ? "yes" : "no") << endl
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;

int main () {
	int N; cin >> N;
	map<int, int> mt; mt[0] = 1;	
	int D;
	rep(i, N) {
		cin >> D;
		if (mt.count(D)) mt[D]++;
		else mt[D] = 1;		
	}
	vi vt;
	for (auto t : mt) vt.push_back(t.first);
	sort(all(vt)); // vdebug(vt);
	vi va; bool f_even = true;
	bool f_double = false;
	for (int D : vt) {
		if (D == 0 || D == 12) {
			if (mt[D] >= 2) {
				f_double = true;
				break;
			} else if (mt[D] == 1) {
				va.push_back(D);
			}
		} else if (0 < D && D < 12) {
			if (mt[D] >= 3) {
				f_double = true;
				break;
			} else if (mt[D] == 2) {
				va.push_back(D);
				va.push_back(24 - D);
			} else if (mt[D] == 1) {
				va.push_back(f_even ? D : 24 - D);
				f_even = !f_even;
			}
		}
	}
	sort(all(va)); // vdebug(va);
	int ans = 12;
	if (f_double) ans = 0;
	else {
		rep(i, va.size() - 1) {
			ans = min(ans, va.at(i + 1) - va.at(i));			
		}
		ans = min(ans, 24 - va.at(va.size() - 1));
	}

	cout << ans << endl;	
}
#define _CRT_SECURE_NO_WARNINGS
#include <cassert>
#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <climits>
using namespace std;

#define int long long
#define pii pair<int, int>
#define ld long double

#define form(i, n) for (int i = 0; i < (n); ++i)
#define form2(i, a, b) for (int i = (a); i < (b); ++i)
#define ford(i, n) for (int i = (n-1); i >= 0; --i)
#define ford2(i, a, b) for (int i = (a-1); i >= (b); --i)

#define chmax(x, v) x = max(x, (v));
#define chmin(x, v) x = min(x, (v));

void solve();
signed main()
{
#ifdef LOCAL_HUGO
	freopen("in.txt", "r", stdin);
#else
	ios::sync_with_stdio(false);
	cin.tie(0);
#endif
	solve();
}

const int UNDEF = -1;
const int borne = 1005;
const int b2 = 20005;
typedef pair<pii, pii> quad;
quad blocs[borne];
int n;
vector<int> valMax;

void solve()
{
	cin >> n;
	form(i, n) {
		int w, s, v;
		cin >> w >> s >> v;
		blocs[i] = { {w + s, s}, {w, v} };
	}
	sort(blocs, blocs + n);
	valMax.assign(b2, 0);
	valMax[0] = 0;
	vector<int> tmp = valMax;
	form(i, n) {
		int s = blocs[i].first.second;
		int w = blocs[i].second.first;
		int v = blocs[i].second.second;
		form(j, s + 1) {
			if (j + w < b2) {
				chmax(tmp[j + w], valMax[j] + v);
			}
		}
		form(i, b2 - 1) chmax(tmp[i+1], tmp[i]);
		valMax = tmp;
	}
	cout << valMax[b2 - 1] << '\n';
}
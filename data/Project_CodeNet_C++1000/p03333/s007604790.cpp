//khodaya khodet komak kon
#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define all(x) x.begin(), x.end()
#pragma GCC optimize ("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize ("-O2")


using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 200000 + 10;
const ll MOD = 1000000000 + 7;
const ll INF = 1000000010;
const ll LOG = 25;

struct Seg{
	int l, r, id;
};

int n, mark[N];
Seg seg[N];
Seg seg2[N];

bool cmp(Seg x, Seg y){
	return x.l > y.l;
}

bool cmp2(Seg x, Seg y){
	return x.r < y.r;
}

int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	ll res = 0;
	for (int i = 1; i <= n; i++){
		cin >>seg[i].l >> seg[i].r;
		seg[i].id = i;
		seg2[i] = seg[i];
	}
	sort(seg + 1, seg + n + 1, cmp);
	sort(seg2 + 1, seg2 + n + 1, cmp2);
	ll ans = 0;
	int cur = 0;
	for (int i = 1; i <= n; i++){
		if (!mark[seg[i].id]){
			mark[seg[i].id] = 1;
			int L = seg[i].l;
			int R = seg[i].r;
			if (L > cur || cur > R){
				if (cur < L) ans += L - cur, cur = L;
				else ans += cur - R, cur = R;
			}
		}
		if (!mark[seg2[i].id]){
			mark[seg2[i].id] = 1;
			int L =seg2[i].l, R = seg2[i].r;
			if (L > cur || cur > R){
				if (cur < L) ans += L - cur, cur = L;
				else ans += cur - R, cur = R;
			}
		}
	}
	ans += abs(cur);
	res = ans;
	memset(mark, 0, sizeof mark);
	ans = 0;
	cur = 0;
	for (int i = 1; i <= n; i++) swap(seg[i], seg2[i]);
	for (int i = 1; i <= n; i++){
		if (!mark[seg[i].id]){
			mark[seg[i].id] = 1;
			int L = seg[i].l;
			int R = seg[i].r;
			if (L > cur || cur > R){
				if (cur < L) ans += L - cur, cur = L;
				else ans += cur - R, cur = R;
			}
		}
		if (!mark[seg2[i].id]){
			mark[seg2[i].id] = 1;
			int L =seg2[i].l, R = seg2[i].r;
			if (L > cur || cur > R){
				if (cur < L) ans += L - cur, cur = L;
				else ans += cur - R, cur = R;
			}
		}
	}
	ans += abs(cur);
	res = max(res, ans);
	cout << res;









	return 0;
}

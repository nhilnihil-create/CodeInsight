#include"bits/stdc++.h"
#include<cassert>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
const int mod = 1000000007;
const int inf = 1ll << 61;
typedef pair<int, int> P;
typedef pair<int, P>PP;
int a[200006];
signed main() {
	int n; cin >> n;
	rep(i, n)cin >> a[i];
	int l = 0, r = 1e7;

	while (r - l > 1) {
		int mi = (l + r) / 2;
		stack<PP>st;
		st.push(PP(1, P(1, a[0])));
	
		for (int i = 1; i < n; i++) {
			PP t = st.top(); st.pop();
			int tn = t.first, tl = t.second.first, tr = t.second.second;

			if (a[i - 1] < a[i]) {
				if (tn == 1) {
					st.push(PP(1, P(tl, a[i])));
				}
				else {
					st.push(t);
					st.push(PP(1, P(tr+1, a[i])));
				}
			}
			else {
				while (tl > a[i]) {
					t = st.top();
					st.pop();
					tn = t.first, tl = t.second.first, tr = t.second.second;
				}
				if (tn != mi) {
					if(tl<=a[i]-1)st.push(PP(tn, P(tl, a[i] - 1)));

					if (st.size()&&st.top().first == tn+1) {
						PP nxt = st.top();
						nxt.second.second = a[i];
						st.pop(); st.push(nxt);
					}
					else st.push(PP(tn + 1, P(a[i],a[i])));
				}
				else {
					if (st.empty()) {
						l = mi; goto Z;
					}
					PP nxt = st.top(); st.pop();
					nxt.second.second--;
					if (nxt.second.first <= nxt.second.second)st.push(nxt);

					if (st.size() && st.top().first == nxt.first + 1) {
						PP nxt2 = st.top();
						nxt2.second.second++;
						st.pop();
						st.push(nxt2);
					}
					else st.push(PP(nxt.first + 1, P(nxt.second.second + 1, nxt.second.second + 1)));
					st.push(PP(1, P(tl, a[i])));
				}
			}
		}
		r = mi;
	Z:;
	}
	cout << r << endl;
}

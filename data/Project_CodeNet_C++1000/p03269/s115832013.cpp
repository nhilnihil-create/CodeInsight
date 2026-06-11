#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define SZ(X) ((int)X.size())

using namespace std;

typedef tuple<int, int, int> iii;

const int MN = 20;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef UTP
	freopen("input.txt", "r", stdin);
	#endif
	int L; cin >> L;
	vector<iii> ans;
	int k = 0;
	for (int i = 0; i < MN; i++) if ((L >> i) & 1)
        k = i;
    int n = k + 1;
    for (int i = 1; i <= k; i++) {
        ans.push_back(iii(i, i + 1, 0));
        ans.push_back(iii(i, i + 1, 1 << (i - 1)));
    }
    for (int i = 0; i < k; i++) if ((L >> i) & 1) {
        L ^= (1 << i);
        ans.push_back(iii(i + 1, n, L));
    }
	cout << n << " " << SZ(ans) << endl;
	for (iii e : ans) {
        int u, v, w;
        tie(u, v, w) = e;
        cout << u << " " << v << " " << w << endl;
	}
	return 0;
}

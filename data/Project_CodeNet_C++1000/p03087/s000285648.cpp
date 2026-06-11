#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define PB push_back
#define MP make_pair

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q; cin >> n >> q;
    int psum[n];
    psum[0] = 0;
    string s; cin >> s;
    vector<pair<int, int>> Q;
    for (int i = 0; i < q; ++i) {
        int l, r; cin >> l >> r;
        l--, r--;
        Q.PB(MP(l, r));
    }
    char prev = s[0];
    for (int i = 1; i < n; ++i) {
        if (prev == 'A' && s[i] == 'C') psum[i] = psum[i - 1] + 1;
        else psum[i] = psum[i - 1];
        prev = s[i];
    }
    for (auto i : Q) {
        cout << psum[i.second] - psum[i.first] << "\n";
    }
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* print new lines
*/
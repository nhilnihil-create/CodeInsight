#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define PB push_back
#define MP make_pair

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
    string s; cin >> s;
    ll k; cin >> k;
    if (k > 1) {
        if (s.size() >= k) {
            bool works = true;
            for (int i = 0; i < k; ++i) {
                if (s[i] != '1') works = false;
            }
            if (works) {
                cout << 1 << "\n";
                return 0;
            }
        }
        for (auto i : s) {
            if (i != '1') {
                cout << i << "\n";
                break;
            }
        }
    } else cout << s[0] << "\n";
}
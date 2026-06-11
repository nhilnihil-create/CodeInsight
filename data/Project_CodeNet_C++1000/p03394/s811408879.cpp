#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n;

int main() {
	cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    set<ll> incl;
    incl.insert(2), incl.insert(3), incl.insert(25);
    int cnt = 3;
    ll sum = 30;
    for (int i = 4; i < 15000; ++i) {
        if (cnt + 2 > n) break;
        int other = 30000 - i;
        if (incl.find(i) == incl.end() && incl.find(other) == incl.end()) {
            if (i % 2 == 0 || i % 3 == 0 || i % 5 == 0) {
                if (other % 2 == 0 || other % 3 == 0 || other % 5 == 0) {
                    incl.insert(i), incl.insert(30000 - i);
                    cnt += 2;
                    sum += 30000;
                }
            }
        }
    }
    if (cnt < n) {
        incl.insert(15000);
        sum += 15000;
        ++cnt;
    }

    for (auto i : incl) {
        cout << i << ' ';
    }
}

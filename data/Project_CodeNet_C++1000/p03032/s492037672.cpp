#include <bits/stdc++.h>
using namespace::std;

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef array<int, 3> tri;
typedef long double ld;

template <class T> istream& operator>>(istream& I, vector<T>& v) {for (T &e: v) I >> e; return I;}
template <class T> ostream& operator<<(ostream &O, const vector<T>& v) {for (const T &e: v) O << e << ' '; return O;}



void _main() {
        int n, k; cin >> n >> k;
        vector<int> a(n); cin >> a;


        int ans = 0;
        for (int left = 0; left <= k; left++) {
                for (int right = 0; right + left <= min(n, k); right++) {
                        vector<int> hand;
                        for (int i = 0; i < left; i++) {
                                hand.emplace_back(a[i]);
                        }
                        for (int i = n - 1; i >= n - right; i--) {
                                hand.emplace_back(a[i]);
                        }
                        sort(all(hand), greater<>());
                        for (int i = 0; i < k - left - right; i++) {
                                if (hand.size() && hand.back() < 0) hand.pop_back();
                                else break;
                        }

                        ans = max(ans, accumulate(all(hand), 0));
                }
        }

        cout << ans;
}



signed main() {
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//        freopen("input.txt", "r", stdin);
        int _t = 1;
//        cin >> _t;
        while (_t--) _main();
        return 0;
}

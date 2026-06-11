#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef tuple<ll, ll, ll> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
#define REP(i,n) for (ll i = 0; i < n; ++i)
#define REPR(i,n) for (ll i = n-1; i >= 0; --i)
#define FOR(i,m,n) for (ll i = m; i < n; ++i)
#define FORR(i,m,n) for (ll i = n-1; i >= m; --i)
#define FORE(x,xs) for (const auto& x : xs)
#define ALL(v) v.begin(), v.end()
#define CHMIN(x,y) x = min(x, y)
#define CHMAX(x,y) x = max(x, y)

const char VACANT = 'V';
const char MALE = 'M';
const char FEMALE = 'F';

int ask(int n) {
    cout << n << endl;
    string s;
    cin >> s;
    if (s[0] == VACANT) exit(0);
    if (s[0] == MALE) return 0;
    return 1;
}

int N;

int solve() {
    int edge_left, edge_right;
    edge_left = edge_right = ask(N-1);
    int left = 0, right = N-2;
    while (right - left > 1) {
        int mid = (left + right) / 2;
        int res = ask(mid);
        if (((edge_left^res)) ^ ((mid^left) & 1)) {
            left = mid+1;
            edge_left = res;
        } else {
            right = mid-1;
            edge_right = res;
        }
    }
    ask(left);
    ask(right);
    if (left > 0) ask(left-1);
    ask(right+1);
}

int main() {
    cin >> N;
    cout << solve();
}
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

const int MAX = 1e4+10;
const string YES = "Yes";
const string NO = "No";

int N;
ll A[MAX], B[MAX];

string solve() {
    ll sum_a = 0, sum_b = 0;
    REP (i, N) {
        sum_a += A[i];
        sum_b += B[i];
    }
    ll k = sum_b - sum_a, count_a = 0, count_b = 0;
    REP (i, N) {
        if (A[i] > B[i]) count_a += A[i] - B[i];
        else if (A[i] < B[i]) count_b += (B[i] - A[i] + 1) / 2;
    }
    if (count_a <= k && count_b <= k) return YES;
    else return NO;
}

int main() {
    cin >> N;
    REP (i, N) cin >> A[i];
    REP (i, N) cin >> B[i];
    cout << solve() << endl;
}
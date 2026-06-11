#define _USE_MATH_DEFINES
#include "bits/stdc++.h"
using namespace std;
#define FOR(i,j,k) for(int (i)=(j);(i)<(int)(k);++(i))
#define rep(i,j) FOR(i,0,j)
#define each(x,y) for(auto &(x):(y))
#define mp make_pair
#define MT make_tuple
#define all(x) (x).begin(),(x).end()
#define debug(x) cout<<#x<<": "<<(x)<<endl
#define smax(x,y) (x)=max((x),(y))
#define smin(x,y) (x)=min((x),(y))
#define MEM(x,y) memset((x),(y),sizeof (x))
#define sz(x) (int)(x).size()
#define RT return
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;

void solve() {
    using E = tuple<int, int, int>;
    int L;
    cin >> L;
    --L;
    int l = L, t = 0;
    for (; (1 << (t + 1)) - 1 <= l; ++t) {
    }
    const int N = t + 1;
    vector<E> ans;
    rep(i, t) {
        ans.emplace_back(i + 1, i + 2, 0);
        ans.emplace_back(i + 1, i + 2, 1 << i);
    }
    l -= 1 << t;
    int base = 1 << t;
    while (l >= 0) {
        for (t = 0; (1 << (t + 1)) - 1 <= l; ++t);
        ans.emplace_back(t + 1, N, base);
        base += 1 << t;
        l -= 1 << t;
    }
    cout << N << ' ' << sz(ans) << endl;
    each(a, ans) {
        int x, y, z;
        tie(x, y, z) = a;
        cout << x << ' ' << y << ' ' << z << endl;
    }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(15);
	solve();
	return 0;
}
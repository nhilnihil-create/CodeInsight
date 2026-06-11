#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 1e5 + 5;

int n, k;
bitset<N> taken;
ll base, groups, ans;

int main() {
	cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    taken.reset();
    set<ll> gc;
    multiset<ll> extra;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>> q;
    rep(i, 0, n) {
        ll a, b;
        cin >> a >> b;
        gc.insert(a);
        q.push({b, a});
    }

    rep(i, 0, k) {
        pii v = q.top();
        q.pop();
        base += v.first;
        if (!taken[v.second]) {
            ++groups;
            taken[v.second] = 1;
        } else {
            extra.insert(v.first);
        }
    }
    
    ans = base + (groups * groups);
    
    while (groups < min(sz(gc), k)) {
        pii v = q.top();
        q.pop();
        if (taken[v.second]) continue;
    
        taken[v.second] = 1;
        base -= *extra.begin();
        extra.erase(extra.begin());
        base += v.first;
        ++groups;
        ans = max(ans, base + (groups * groups));
    }

    cout << ans;
}

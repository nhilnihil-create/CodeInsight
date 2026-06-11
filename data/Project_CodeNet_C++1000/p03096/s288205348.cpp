#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
#define PI 3.14159265358979
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repp(i, s, e) for(int i = (s); i <= (e); ++i)
#define sz(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define FAST_IO() ios::sync_with_stdio(0); cin.tie(0)
template<typename T>
ostream& operator<<(ostream &os, const vector<T> &v) { for (auto x : v) os << x << " "; return os << "\n"; }
template<class U, class V>
ostream& operator<<(ostream &os, const pair<U, V> &p) { return os << "(" << p.first << "," << p.second << ")";}

const int MAXN = 2e5 + 5;
const ll MOD = 1e9 + 7;
int N, A[MAXN], cache[MAXN];
vector<int> pos[MAXN];

int cnt(int start) {
    int &ret = cache[start];
    if(ret != -1) return ret;
    if(start == N - 1) return 1;
    auto it = upper_bound(all(pos[A[start]]), start);
    if(it == pos[A[start]].end()) {
        return ret = cnt(start + 1);
    } else {
        int next = it - pos[A[start]].begin();
        if(pos[A[start]][next] == start + 1) {
            return ret = cnt(start + 1);
        } else {
            return ret = (cnt(start + 1) + cnt(pos[A[start]][next])) % MOD;
        }
    }
}

int main() {
    FAST_IO();
    cin >> N;
    rep(i, N) {
        cin >> A[i];
        --A[i];
        pos[A[i]].push_back(i);
    }
    // cnt(start)
    memset(cache, -1, sizeof(cache));
    cout << cnt(0) << "\n";
}

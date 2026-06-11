#include <bits/stdc++.h>
using namespace std;

#define rep(i, j) for (int i = 0; i < j; i++)
#define all(obj) (obj).begin(), (obj).end()
#define rall(obj) (obj).rbegin(), (obj).rend()
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;

template<class T,class U> void chmax(T& a, U b) {if(a<b)a=b;}
template<class T,class U> void chmin(T& a ,U b) {if(b<a)a=b;}

vector<int> edges[10000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    vector<pii> ab(n - 1);
    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        ab[i].first = a;
        ab[i].second = b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    vi c(n);
    rep(i, n) {
        cin >> c[i];
    }
    sort(rall(c));

    vi d(n, -1);
    deque<int> deq;
    deq.push_back(0);
    ll ans = 0;
    int idx = 0;
    while(!deq.empty()) {
        int u = deq.front(); deq.pop_front();
        if (d[u] >= 0) continue;
        d[u] = c[idx++];
        for(auto v : edges[u]) {
            if (d[v] >= 0) continue;
            deq.push_back(v);
        }
    }

    rep(i, n - 1) {
        ans += min(d[ab[i].first], d[ab[i].second]);
        // cout << ab[i].first << " " << ab[i].second << endl;
    }

    cout << ans << endl;
    rep(i, n) {
        cout << d[i] << " ";
    }
    cout << endl;


    return 0;
}

#include <bits/stdc++.h>
#define REP(i, n) for(ll i = 0; i < (ll)n; i++)
#define FOR(i, a, b) for(ll i = (a); i < (ll)b; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF (1ll << 60)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
using vl = vector<ll>;
using vvl = vector<vl>;
typedef double db;
typedef string str;
typedef pair<ll, ll> p;
constexpr int MOD = 1000000007;
using ll = long long;
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

void print(const std::vector<ll> &v) {
    std::for_each(v.begin(), v.end(), [](ll x) { std::cout << x << " "; });
    std::cout << std::endl;
}

int main() {
    int N;
    cin >> N;
    vector<int> a(N - 1), b(N - 1);
    vvl edge(N);
    REP(i, N - 1) {
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
        edge[b[i]].push_back(a[i]);
        edge[a[i]].push_back(b[i]);
    }
    vector<pair<int, int>> res;
    REP(i, N) {
        res.push_back(make_pair(-edge[i].size(), i));
    } //サイズが大きいものにじゅんになる番号
    sort(res.begin(), res.end());
    vl c(N);
    REP(i, N) { cin >> c[i]; }
    //一番大きい数字以外いけそう
    sort(c.begin(), c.end());
    ll sum = accumulate(c.begin(), c.end(), 0LL);
    sum -= c[N - 1];
    cout << sum << endl;
    reverse(c.begin(), c.end());
    // cを降順にソートする
    //スターになるべくおおきな数字を割り当てる
    int star = res[0].second;
    queue<int> que;
    que.push(star);
    vector<ll> ans(N, 0);
    ans[star] = c[0];
    int cnt = 0;
    while(!que.empty()) {
        int v = que.front();
        que.pop();
        for(int nv : edge[v]) {
            if(ans[nv] == 0) {

                cnt++;
                ans[nv] = c[cnt];
                que.push(nv);
            }
        }
    }
    print(ans);
    cout << endl;
}
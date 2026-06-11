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

void print(const std::vector<int> &v) {
    std::for_each(v.begin(), v.end(), [](int x) { std::cout << x << " "; });
    std::cout << std::endl;
}
// http://drken1215.hatenablog.com/entry/2019/04/01/165200
// 左側の落ちる区間と、落ちない区間の境目
// 右側の落ちる区間と、落ちない区間の境目
// をにぶたんで求めることができる

using pchar = pair<char, char>;

//にぶたん判定パート
// sはマスに書かれてる文字列
// posは位置
// tdはいままでのすべての呪文
int simulate(const string &s, const vector<pchar> &td, int pos) {
    for(auto c : td) {
        if(s[pos] != c.first) {
            continue;
        }
        if(c.second == 'L') {
            pos--;
        } else {
            pos++;
        }
        if(pos < 0) {
            return -1;
        } else if(pos >= (int)s.size()) {
            return 1;
        }
    }
    return 0;
}
//にぶたん
int solve(int N, const string &s, const vector<pchar> &td) {
    int low = -1;
    int high = N;
    while(high - low > 1) {
        int mid = (low + high) / 2;
        if(simulate(s, td, mid) == -1) {
            low = mid;
        } else {
            high = mid;
        }
    }
    int left_fall = high;
    low = -1;
    high = N;
    while(high - low > 1) {
        int mid = (low + high) / 2;
        if(simulate(s, td, mid) == 1) {
            high = mid;
        } else {
            low = mid;
        }
    }
    int right_fall = N - 1 - low;
    return N - (left_fall + right_fall);
}
int main() {
    int N, Q;
    string s;
    cin >> N >> Q >> s;
    vector<pchar> td(Q);
    REP(i, Q) { cin >> td[i].first >> td[i].second; }
    cout << solve(N, s, td) << endl;
}
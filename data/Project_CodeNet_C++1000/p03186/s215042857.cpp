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
// http://drken1215.hatenablog.com/entry/2019/03/24/091900
int main() {
    int A, B, C;
    cin >> A >> B >> C;
    //解毒剤入りの美味しくないクッキーを A
    //解毒剤入りの美味しいクッキーをB
    //毒入りの美味しいクッキーを C 枚持っていま
    //美味しいクッキー
    if(A + B >= C - 1) {
        //毒は全部食べれる
        cout << B + C << endl;
        return 0;
    }
    cout << A + B + 1 + B << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define Rep(i, k, n) for (int i = k; i < (int)(n); i++)
#define RRep(i, k, n) for (int i = k; i > (int)(n); i--)
#define COUT(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl
#define ALL(a)  (a).begin(),(a).end()
#define rALL(a)  (a).rbegin(),(a).rend()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T> void PrintVector(const vector<T> &vec) {for (auto val : vec) cout << val << " "; cout << endl;}
const long long INF = 1LL << 60;
const int MOD = 1000000007;
const double PI = acos(-1); //3.14~
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

vector<Pll> prime_factorize(ll N) {
    vector<Pll> res;
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        long long ex = 0; // 指数

        // 割れる限り割り続ける
        while (N % a == 0) {
            ++ex;
            N /= a;
        }

        // その結果を push
        res.push_back({a, ex});
    }

    // 最後に残った数について
    if (N != 1) res.push_back({N, 1});
    return res;
}

int n;
map<ll, int> sisuu;

ll rec(map<ll, int> ::iterator p, ll mul)
{
    if (p == sisuu.end())
    {
        if (mul == 1) return 1;
        else return 0;
    }
    ll ans = 0;
    rep(i, p->second + 1)
    {
        if (mul % (i + 1) != 0) continue;
        p++;
        ans += rec(p, mul / (i + 1));
        --p;
    }
    return ans;
}

int main()
{
    cin >> n;
    Rep(i, 2, n + 1)
    {
        auto ps = prime_factorize(i);
        for (auto it : ps) sisuu[it.first] += it.second; // second = 指数の数
    }
    cout << rec(sisuu.begin(), 75) << endl;
}
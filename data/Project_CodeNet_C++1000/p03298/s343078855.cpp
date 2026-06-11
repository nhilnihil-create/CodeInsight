#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

#define REP(i,n) for(int i=0;i<n;++i)
#define SORT(name) sort(name.begin(), name.end())
#define ZERO(p) memset(p, 0, sizeof(p))
#define MINUS(p) memset(p, -1, sizeof(p))
#if 1
#  define DBG(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else
#  define DBG(fmt, ...)
#endif

const ll LLINF = (1LL<<60);
const int INF = (1LL<<30);
const double DINF = std::numeric_limits<double>::infinity();
const int MOD = 1000000007;
#define MAX_N 100010

int N;
string S;
map< pair<string, string>, int> pat_l;   // first: 文字列パターン second: それが出てくる回数
map< pair<string, string>, int> pat_r;

void make_pat(map< pair<string, string>, int>& pat, string s) {
    ll fact = 1;
    REP(i, N) { fact *= 2; }
    REP(i, fact) {
        string first_s = "", second_s = "";
        REP(j, N) {
            if((i >> j) & 1) { first_s += s[j]; }
            else { second_s += s[j]; }
        }
        pat[make_pair(first_s, second_s)]++;
    }
}

signed main()
{
    cin >> N >> S;

    // pat の作成
    string s_l = S.substr(0, N);
    string s_r = S.substr(N, N);
    reverse(s_r.begin(), s_r.end());

    make_pat(pat_l, s_l);
    make_pat(pat_r, s_r);

    ll ans = 0;
    for(auto& pat : pat_l) {
        pair<string, string> p = pat.first;
        swap(p.first, p.second);
        if(pat_r.count(p) != 0) {
            ans += pat.second * pat_r[p];
        }
    }
    printf("%lld\n", ans);

    return 0;
}

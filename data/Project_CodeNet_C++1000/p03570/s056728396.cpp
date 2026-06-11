#include"bits/stdc++.h"
using namespace std;
#define REP(k,m,n) for(int (k)=(m);(k)<(n);(k)++)
#define rep(i,n) REP((i),0,(n))
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using tp3 = tuple<int, int, int>;
using Mat = vector<vector<ll>>;
constexpr int INF = 1 << 28;
constexpr ll INFL = 1ll << 60;
constexpr int dh[4] = { 0,1,0,-1 };
constexpr int dw[4] = { -1,0,1,0 };
bool isin(const int H, const int W, const int h, const int w) {
    return 0 <= h && h < H && 0 <= w && w < W;
}
// ============ template finished ============
constexpr int SIZE = 26;
using ALPHA = bitset<SIZE>;

vector<ALPHA> parse_bits(const string& s) {
    const int len = s.size();
    vector<ALPHA> res(len + 1, 0);
    rep(i, len) {
        int idx = s[i] - 'a';
        ALPHA buf(1 << idx);
        res[i + 1] = res[i] ^ buf;
    }
    return res;
}

unordered_map<ALPHA, set<int>> compress(const vector<ALPHA>& bits) {
    unordered_map<ALPHA, set<int>> mp;
    rep(i, bits.size())mp[bits[i]].insert(i);
    return mp;
}

unordered_set<ALPHA> make_nexts(ALPHA bit) {
    unordered_set<ALPHA> st;
    rep(i, SIZE) {
        ALPHA buf(1 << i);
        bit ^= buf;
        st.insert(bit);
        bit ^= buf;
    }
    return st;
}

void even_palindrome_transition(
    vector<int>& dp,
    const unordered_map<ALPHA, set<int>>& mp,
    const vector<ALPHA>& bits,
    const int i
) {
    const auto& st = mp.at(bits[i]);
    const auto itr = st.upper_bound(i);
    if (itr != st.end()) {
        int idx = *itr;
        dp[idx] = min(dp[idx], dp[i] + 0);
    }
}

void odd_palindrome_transition(
    vector<int>& dp,
    const unordered_map<ALPHA, set<int>>& mp,
    const vector<ALPHA>& bits,
    const int i
) {
    const auto nexts = make_nexts(bits[i]);
    for (auto next : nexts) {
        if (mp.find(next) == mp.end())continue;
        const auto& st = mp.at(next);
        const auto itr = st.lower_bound(i);
        if (itr != st.end()) {
            int idx = *itr;
            dp[idx] = min(dp[idx], dp[i] + 1);
        }
    }
}

int main()
{
    string s;
    cin >> s;

    auto bits = parse_bits(s);
    auto mp = compress(bits);
    const int len = s.size();
    vector<int> dp(len + 1, INF);

    dp[0] = 0;
    rep(i, len) {
        even_palindrome_transition(dp, mp, bits, i);
        odd_palindrome_transition(dp, mp, bits, i);
    }
    int res = dp.back();
    cout << (res == 0 ? 1 : res) << endl;
    return 0;
}

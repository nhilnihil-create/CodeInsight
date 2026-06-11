#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for(int(i) = 0; (i) < (n); (i)++)
#define FOR(i, m, n) for(int(i) = (m); (i) < (n); (i)++)
#define All(v) (v).begin(), (v).end()
#define pb push_back
#define MP(a, b) make_pair((a), (b))
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;
const int MOD = 1e9 + 7;

int main() {
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    bool f = 0, b = 0;
    if(S.back() == '0') {
        f = 1;
        S += '1';
    }
    reverse(All(S));
    if(S.back() == '0') {
        b = 1;
        S += '1';
    }
    N = S.size();
    int c = 0;
    vector<int> v;
    for(int i = 0; i < N; i++) {
        c++;
        if(i + 1 == N || S[i] != S[i + 1]) {
            v.pb(c);
            c = 0;
        }
    }
    int len = 2 * K + 1;
    int tmp = 0;
    int res = 0;
    if(len > v.size()) {
        for(auto x : v)
            res += x;
        cout << res - f - b << endl;
        return 0;
    }
    for(int i = 0; i + len - 1 < v.size(); i += 2) {
        if(i == 0) {
            for(int j = 0; j < len; j++) {
                tmp += v[j];
            }
        } else {
            tmp += v[i + len - 2] + v[i + len - 1];
        }
        int tmp2 = tmp;
        if(f && i == 0)
            tmp--;
        if(b && i + len == v.size())
            tmp--;
        res = max(tmp, res);
        tmp = tmp2;
        tmp -= v[i] + v[i + 1];
    }
    cout << res << endl;
    return 0;
}
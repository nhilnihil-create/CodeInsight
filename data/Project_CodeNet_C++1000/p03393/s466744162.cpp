#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <iomanip>
#include <map>
#include <set>
#include <cmath>
#include <cstdio>
#include <cstdint>
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
    string S;
    cin >> S;
    set<char> se;
    rep(i, S.size()) { se.insert(S[i]); }
    if(S == "zyxwvutsrqponmlkjihgfedcba") {
        cout << -1 << endl;
        return 0;
    }
    if(S.size() == 26) {
        for(int i = S.size() - 1; i >= 0; i--) {
            for(int j = S[i] - 'a' + 1; j < 26; j++) {
                int flag = 0;
                for(int k = 0; k < i; k++) {
                    if(S[k] == (char)('a' + j))
                        flag = 1;
                }
                if(flag == 0) {
                    cout << S.substr(0, i) + (char)('a' + j) << endl;
                    return 0;
                }
            }
        }
    } else {
        for(int i = 0; i < 26; i++) {
            if(!se.count((char)('a' + i))) {
                cout << S << (char)('a' + i) << endl;
                return 0;
            }
        }
    }
    return 0;
}
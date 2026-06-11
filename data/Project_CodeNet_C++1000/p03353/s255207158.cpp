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
    string S;
    cin >> S;
    int K;
    cin >> K;
    int N = S.size();
    set<string> strs;
    for(int i = 0; i < N; i++) {
        string s = "";
        for(int j = i; j < N; j++) {
            s += S[j];
            strs.insert(s);
            if(s.size() == 5)
                break;
        }
    }
    auto it = strs.begin();
    rep(i, K - 1) it++;
    cout << *it << endl;
    return 0;
}
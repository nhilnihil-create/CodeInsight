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
    int N = S.size();
    int l = 0, r = N - 1;
    int res = 0;
    while(r >= l) {
        if(S[l] == S[r]) {
            l++;
            r--;
            continue;
        }
        if(S[l] == 'x' && S[r] != 'x') {
            res++;
            l++;
            continue;
        }
        if(S[l] != 'x' && S[r] == 'x') {
            res++;
            r--;
            continue;
        }
        if(S[l] != S[r]) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << res << endl;
    return 0;
}
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
    int H, W, N;
    cin >> H >> W >> N;
    int sx, sy;
    cin >> sy >> sx;
    string S, T;
    cin >> S >> T;
    int L = 0, D = H + 1, R = W + 1, U = 0;
    for(int i = S.size() - 1; i >= 0; i--) {
        if(i != S.size() - 1) {
            char c = T[i];
            if(c == 'L')
                R++;
            else if(c == 'R')
                L--;
            else if(c == 'U')
                D++;
            else if(c == 'D')
                U--;
        }
        U = max(0, U);
        L = max(0, L);
        R = min(W + 1, R);
        D = min(H + 1, D);

        char c = S[i];
        if(c == 'L')
            L++;
        else if(c == 'R')
            R--;
        else if(c == 'U')
            U++;
        else if(c == 'D')
            D--;
        U = max(0, U);
        L = max(0, L);
        R = min(W + 1, R);
        D = min(H + 1, D);
        if(L + 1 == R || U + 1 == D) {
            cout << "NO" << endl;
            return 0;
        }
    }
    if(sx > L && sx < R && sy > U && sy < D) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
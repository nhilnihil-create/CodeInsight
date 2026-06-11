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
    int M, K;
    cin >> M >> K;
    if(M == 0 && K == 0) {
        cout << 0 << " " << 0 << endl;
        return 0;
    } else if(M == 1 && K == 0) {
        cout << 1 << " " << 0 << " " << 0 << " " << 1 << endl;
        return 0;
    } else if(M >= 2 && K < (1 << M)) {
        int now = (1 << M) - 1;
        while(now >= 0) {
            if(now != K)
                cout << now << " ";
            now--;
        }
        cout << K << " ";
        now = 0;
        while(now <= (1 << M) - 1) {
            if(now != K)
                cout << now << " ";
            now++;
        }
        cout << K << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}
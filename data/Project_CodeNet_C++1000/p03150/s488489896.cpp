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
    if(S.substr(0, 7) == "keyence" || S.substr(S.size() - 7, 7) == "keyence") {
        cout << "YES" << endl;
    } else {
        for(int i = 1; i <= 6; i++) {
            string front = S.substr(0, i);
            string back = S.substr(S.size() - (7 - i), 7 - i);
            if(front + back == "keyence") {
                cout << "YES" << endl;
                return 0;
            }
        }
        cout << "NO" << endl;
    }
    return 0;
}
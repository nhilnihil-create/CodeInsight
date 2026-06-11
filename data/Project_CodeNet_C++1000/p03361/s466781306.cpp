#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower, islower

#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long; using ld = long double;
using P = pair<int, int>;

int main() {
    int dh[4] = {1, 0, -1, 0};
    int dw[4] = {0, 1, 0, -1};
    int h, w;
    cin >> h >> w;
    string a[h];
    rep(i,h) cin >> a[i];
    bool canf = true;
    rep(i,h) rep(j,w) {
            if (a[i][j] == '.') continue;
            bool canp = false;
            rep (k,4) {
                int ni = i + dh[k];
                int nj = j + dw[k];
                if (ni < 0 || ni >= h) continue;
                if (nj < 0 || nj >= w) continue;
                if (a[ni][nj] == '#') canp = true;
            }
            if (!canp) {
                canf = false;
                break;
            }
        }
    if (canf) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}


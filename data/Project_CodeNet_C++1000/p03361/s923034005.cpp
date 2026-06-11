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
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <math.h>
#include <cstdlib>
#define rep(i,x) for(int i=0;i<x;i++)
#define all(a) (a).begin(),(a).end()
using namespace std;
using ld = long double;
using ll = long long;
const ll INF = 10010010010;
typedef pair<ll, ll> P;
const ll mod = 1000000007;
ll gcd(ll a, ll b) {//a>b
    if (a < b)swap(a, b);
    if (a % b == 0) return b;
    else return gcd(b, a % b);
}
const int dx[4] = {1,0,0,-1};
const int dy[4] = { 0,1,-1,0 };

int main() {
    ll H, W;
    cin >> H >> W;//tate h yoko w
    vector<vector<char>> moji(H, vector<char>(W));
    vector<vector<bool>> visit(H, vector<bool>(W,true));
    rep(i, H) {
        rep(j, W) {
            cin >> moji[i][j];
            if (moji[i][j] == '#')visit[i][j] = false;
        }
    }
/*
3 3
.#.
###
.#.
*/
    bool ans = true;
    rep(i, H) {
        rep(j, W) {
            if (!(visit[i][j])) {
                bool ok = false;
                rep(d, 4) {
                    ll dh = i + dx[d]; ll dw = j + dy[d];
                    if (dh >= 0 && dw >= 0 && dh < H && dw < W) {
                        if (moji[dh][dw] == '#') {
                            ok = true;
                            visit[i][j] = true;
                        }
                    }
                }
                if (!(ok)) {
                    ans = false;
                }
            }
        }
    }
    if (ans)cout << "Yes" << endl;
    else cout << "No" << endl;
}
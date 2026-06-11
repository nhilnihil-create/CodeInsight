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
#include <iomanip>
#define rep(i,x) for(ll i=0;i<x;i++)
#define all(a) (a).begin(),(a).end()
using namespace std;
using ld = long double;
using ll = long long;
const ll INF = 10010010010;
typedef pair<ll, ll> P;
using graph = vector<vector<ll>>;
const ll mod = 1000000007;
ll gcd(ll a, ll b) {//a>b
    if (a < b)swap(a, b);
    if (a % b == 0) return b;
    else return gcd(b, a % b);
}/*フィボナッチテンプレ
ll memo[50];
ll fibo(ll n) {
    if (memo[n] != 0)return memo[n];
    if (n <= 1)return memo[n] = n;
    else return memo[n] = fibo(n - 1) + fibo(n - 2);
}
*/
bool isp(ll n) {
    bool res = true;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            res = false;
            break;
        }
    }
    return res;
}
const ll dx[4] = { 1,0,0,-1 };
const ll dy[4] = { 0,1,-1,0 };
ll H, W;
queue<P> que;
char maze[55][55];
ll dist[55][55];
ll bfs() {//sx = 0,sy = 0,gx = H - 1,gy = W - 1 
    que.push(P(0, 0));
    dist[0][0] = 0;
    while (que.size()) {
        P p = que.front();
        que.pop();
        if (p.first == H - 1 && p.second == W - 1)break;
        for (int i = 0; i < 4; i++) {
            ll dh = p.first + dx[i];
            ll dw = p.second + dy[i];
            if (dh < 0 || dw < 0 || dh >= H || dw >= W)continue;
            if (maze[dh][dw] != '#' && dist[dh][dw] == INF) {
                dist[dh][dw] = dist[p.first][p.second] + 1;
                que.push(P(dh, dw));
            }
        }
    }
    return dist[H - 1][W - 1];
}
int main() {
    cin >> H >> W;
    ll cnt = 0;
    rep(i, H) {
        rep(j, W) {
            cin >> maze[i][j];
            dist[i][j] = INF;
            if (maze[i][j] == '#')cnt++;
        }
    }
    ll num = bfs();
    if (num == INF)cout << "-1" << endl;
    else {
        cout << H * W - cnt - num - 1 << endl;
    }
}
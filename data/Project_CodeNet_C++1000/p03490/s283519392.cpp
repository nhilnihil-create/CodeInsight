#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

template <class T>
vector<T> make_v(size_t size, const T& init){ return vector<T>(size, init); }

template<class... Ts>
auto make_v(size_t size, Ts... rest) {
    return vector<decltype(make_v(rest...))>(size, make_v(rest...));
}
int main() {
    string s;
    int x, y;
    cin >> s >> x >> y;
    vector<int> vx;
    vector<int> vy;
    int p = 0, q = 0;
    auto mx = make_v(2, 20000, 0);
    auto my = make_v(2, 20000, 0);
    mx[0][10000] = 1, my[0][10000] = 1;
    for (auto &&i : s) {
        if (i == 'T') {
            if (q == 0) {
                p++;
                continue;
            }
            if (p % 2) {
                vy.emplace_back(q);
            } else {
                if(p == 0) mx[0][10000]--, mx[0][10000+q]++;
                else vx.emplace_back(q);
            }
            q = 0;
            p++;
        } else {
            q++;
        }
    }
    if (q != 0) {
        if (p % 2) {
            vy.emplace_back(q);
        } else {
            if(p == 0) mx[0][10000]--, mx[0][10000+q]++;
            else vx.emplace_back(q);
        }
    }

    for (int i = 0; i < vx.size(); ++i) {
        int now = i&1, nxt = now^1;
        fill(mx[nxt].begin(), mx[nxt].end(), 0);
        for (int j = 0; j < 20000; ++j) {
            if(mx[now][j]){
                mx[nxt][j+vx[i]] = 1;
                mx[nxt][j-vx[i]]= 1;
            }
        }
    }
    for (int i = 0; i < vy.size(); ++i) {
        int now = i&1, nxt = now^1;
        fill(my[nxt].begin(), my[nxt].end(), 0);
        for (int j = 0; j < 20000; ++j) {
            if(my[now][j]){
                my[nxt][j+vy[i]] = 1;
                my[nxt][j-vy[i]]= 1;
            }
        }
    }
    if(mx[vx.size()%2][x+10000] && my[vy.size()%2][y+10000]) puts("Yes");
    else puts("No");
    return 0;
}

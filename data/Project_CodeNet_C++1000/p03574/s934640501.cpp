#include <iostream>
#include <numeric>
#include <cmath>
#include <limits>
#include <cstring>
#include <stdio.h>
#include <iomanip>
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
using namespace std;
using ll = long long;
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)
ll Max(ll(a), ll(b), ll(c)) {
	return max(max(a, b), c);
}
ll Min(ll(a), ll(b), ll(c)) {
	return min(min(a, b), c);
}

using Graph = vector<vector<int>>;

// 深さ優先探索
vector<bool> seen;
void dfs(const Graph& G, int v) {
    seen[v] = true; // v を訪問済にする

    // v から行ける各頂点 next_v について
    for (auto next_v : G[v]) {
        if (seen[next_v]) continue; // next_v が探索済だったらスルー
        dfs(G, next_v); // 再帰的に探索
    }
}



int main() {
    ll H, W;
    cin >> H >> W;
    vector<ll> dx = { 1,1,1,0,0,-1,-1,-1 };
    vector<ll> dy = { 1,0,-1,1,-1,1,0,-1 };
    vector<vector<char>> data(H+2, vector<char>(W+2));
    rep(i, H+2) {
        data.at(i).at(0) == '!';
        data.at(i).at(W+1) == '!';
    }
    rep(i, W + 2) {
        data.at(0).at(i) == '!';
        data.at(H+1).at(i) == '!';
    }
    rep(i, H) {
        string S;
        cin >> S;
        rep(j, W) {
            data.at(i + 1).at(j + 1) = S.at(j);
        }
    }

    rep(i, H) {
        rep(j, W) {
            if(data.at(i + 1).at(j + 1) =='#'){
                cout << '#';
                continue;
            }
            else {
                ll a = 0;
                rep(k, 8) {
                    if (data.at(i + 1 + dx.at(k)).at(j + 1 + dy.at(k)) == '#') {
                        a++;
                    }

                }
                cout << a;
            }
        }
        cout << endl;
    }
}
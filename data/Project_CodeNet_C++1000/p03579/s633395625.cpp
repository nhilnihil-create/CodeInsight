#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define MOD 1000000007
using namespace std;

typedef pair<int, int> P;
typedef pair<long long, long long> LLP;

// 連結な重みなしグラフGは二部グラフであるか？
// 二部グラフなら各頂点集合の要素数をPairで返し，そうでなければmake_pair(-1, -1)を返す．
LLP getBipartiteGraphCount(vector< vector<long long> > G) {
    vector<long long> color(G.size(), 0);
    stack<long long> st;
    st.push(0);
    color[0] = 1;
    bool isBipartite = true;

    while (!st.empty()) {
        int p = st.top(); st.pop();
        for (int i = 0; i < G[p].size(); i++) {
            if (color[G[p][i]] == color[p]) {
                // G is not bipartite
                isBipartite = false;
                while(!st.empty()) st.pop();
                break;
            }
            if (color[G[p][i]] == 0) {
                st.push(G[p][i]);
                color[G[p][i]] = (-1) * color[p];
            }
        }
    }
    if (isBipartite) {
        long long countPlus = 0;
        long long countMinus = 0;

        for (int i = 0; i < G.size(); i++) {
            if (color[i] > 0) countPlus++;
            else if (color[i] < 0) countMinus++;
        }
        // if countPlus + countMinus < G.size(), G is not connected
        return (countPlus + countMinus == G.size() ? make_pair(countPlus, countMinus) : make_pair((long long)-1, (long long)-1));
    } else return make_pair(-1, -1);
}

int main() {

    long long N, M;
    cin >> N >> M;

    vector< vector<long long> > G(N, vector<long long>(0));
    for (int i = 0; i < M; i++) {
        long long A, B;
        cin >> A >> B;
        A--; B--;
        G[A].push_back(B);
        G[B].push_back(A);
    }

    LLP result = getBipartiteGraphCount(G);

    if (result.first > 0) cout << (result.first * result.second - M) << endl;
    else cout << (N * (N - 1) / 2 - M) << endl;

    return 0;
}
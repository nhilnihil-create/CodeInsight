/* ---------- STL Libraries ---------- */
// IO library
#include <cstdio>
#include <fstream>
#include <iomanip>
#include <ios>
#include <iostream>

// algorithm library
#include <algorithm>
#include <cmath>
#include <numeric>
#include <random>
#include <cstring>

// container library
#include <array>
#include <bitset>
#include <deque>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <vector>
#include <stack>

/* ---------- Namespace ---------- */
using namespace std;

/* ---------- Type ---------- */
using ll = long long;
#define int ll
#define P pair<ll, ll>

/* ---------- Constants  */
const double PI = 3.141592653589793238462643383279;
const ll MOD = 1e9 + 7;
const int INF = 1LL << 55;

/* v-v-v-v-v-v-v-v-v Main Part v-v-v-v-v-v-v-v-v */
signed main() {
    int N, M;
    cin >> N >> M;

    char colors[N];
    string line;
    cin >> line;
    for (int i = 0; i < N; i++) colors[i] = line[i];

    vector<int> a_cnts(N, 0);
    vector<int> b_cnts(N, 0);
    vector<vector<int>> table(N);

    for (int i = 0; i < M; i++) {
        int s, t;
        cin >> s >> t;
        s--; t--;
        table[s].push_back(t);
        table[t].push_back(s);

        if (colors[s] == 'A') a_cnts[t]++;
        else b_cnts[t]++;

        if (colors[t] == 'A') a_cnts[s]++;
        else b_cnts[s]++;
    }

    vector<bool> removed(N, false);

    stack<int> st;
    for (int i = 0; i < N; i++) {
        if (a_cnts[i] == 0 || b_cnts[i] == 0) {
            st.push(i);
            removed[i] = true;
        }
    }

    while (!st.empty()) {
        int node = st.top(); st.pop();
        for (int next : table[node]) {
            if (removed[next]) continue;

            if (colors[node] == 'A') a_cnts[next]--;
            else b_cnts[next]--;

            if (a_cnts[next] == 0 || b_cnts[next] == 0) {
                st.push(next);
                removed[next] = true;
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < N; i++) if (removed[i]) cnt++;
    if (cnt == N) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }

    return 0;
}
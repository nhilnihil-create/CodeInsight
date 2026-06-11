#include <algorithm>
#include <cassert>
#include <climits>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}

const int INF = 1e9;
const long long LINF = 1e18;

int main() {
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> edges(M);

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        edges[i] = pair<int, int>(b, a);
    }

    sort(edges.begin(), edges.end());

    int ans = 1;
    int right = edges[0].first;
    for (int i = 1; i < M; i++) {
        if (right <= edges[i].second) {
            ans++;
            right = edges[i].first;
        }
    }

    cout << ans << endl;
    return 0;
}

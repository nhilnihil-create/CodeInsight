#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <utility>
#include <iomanip>
#include <tuple>
#include <numeric>
#include <cstdio>
#include <cmath>
using namespace std;
using ll = long long;
const int INF = 1e9;

int a, b, c;
int N, rtn = INF;
vector<int> l(8);

void dfs(int depth, vector<pair<int, int>>& abcd) {
    if (depth == N) {
        if (abcd[0].second == 0 || abcd[1].second == 0 || abcd[2].second == 0) return;
        int irtn = abs(a - abcd[0].first) + abs(b - abcd[1].first) + abs(c - abcd[2].first);
        for (int i = 0; i < 3; i++) {
            if (abcd[i].second >= 2) irtn += (10 * (abcd[i].second - 1));
        }
        // cout << "irtn=" << irtn << " " << "a=" << abcd[0].second << " " << "b=" << abcd[1].second << " " << "c=" << abcd[2].second << endl;
        rtn = min(rtn, irtn);
        return;
    }
    for (int i = 0; i < 4; i++) {
        abcd[i].first += l[depth];
        abcd[i].second++;
        dfs(depth+1, abcd);
        abcd[i].first -= l[depth];
        abcd[i].second--;
    }
}

int main() {
    cin >> N >> a >> b >> c;
    vector<pair<int, int>> abcd(4);
    for (int i = 0; i < N; i++) cin >> l[i];
    dfs(0, abcd);
    cout << rtn << endl;
}
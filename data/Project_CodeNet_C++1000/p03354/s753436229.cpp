#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;

int myfind(int a, vector<int>& relation) {
    if (relation[a] == a) return a;
    int res = myfind(relation[a], relation);
    relation[a] = res;
    return res;
}

void myunion(int a, int b, vector<int>& relation) {
    int ta = myfind(a, relation);
    int tb = myfind(b, relation);
    if (ta == tb) return;
    relation[ta] = tb;
}


int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n + 1, 0);
    vector<int> relation(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        // cin >> v[i];
        scanf("%d", &v[i]);
        relation[i] = i;
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        // cin >> a >> b;
        scanf("%d%d", &a, &b);
        myunion(a, b, relation);
    }
    vector<vector<int>> um(n + 1, vector<int>(0));
    for (int i = 1; i <= n; i++) {
        int t = myfind(i, relation);
        um[t].push_back(i);
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (um[i].size() == 0) continue;
        vector<int> nodes = um[i];
        unordered_map<int, int> c;
        // vector<int> c(n + 1, 0);
        for (auto node : nodes) {
            c[node]++;
            if (c[node] == 2) res++;
            c[v[node]]++;
            if (c[v[node]] == 2) res++;
        }
    }
    cout << res << endl;
}

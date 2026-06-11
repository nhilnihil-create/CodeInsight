#include <bits/stdc++.h>
#include <unordered_map>
 
using namespace std;

int dv;
int maxDepth = -1;
int findDeepestV(int v, unordered_map<int, vector<int> > mp) {
    int visit[200001] = {0, }, cnt = -1;
    queue<pair<int, int> > q;
    q.push(make_pair(v, 1));
    visit[v] = 1;
    while (q.size() != 0) {
        pair<int, int> now = q.front();
        q.pop();
        if (cnt < now.second) cnt = now.second;
        for (auto child : mp[now.first]) {
            if (visit[child] == 0) {
                visit[child] = 1;
                q.push(make_pair(child, now.second + 1));
                dv = child;
            }
        }
    }
    return cnt;
}

int getDiameter(unordered_map<int, vector<int> > mp) {
    findDeepestV(1, mp);
    return findDeepestV(dv, mp);
}
 
int main() {
    ios::sync_with_stdio(false);

    int n, i, a, b;
    cin >> n;
    unordered_map<int, vector<int> > mp;
    for (i = 0; i < n - 1; i++) {
        cin >> a >> b;
        if (mp.find(a) == mp.end()) {
            mp.insert(make_pair(a, vector<int>()));
        }
        mp[a].push_back(b);
        if (mp.find(b) == mp.end()) {
            mp.insert(make_pair(b, vector<int>()));
        }
        mp[b].push_back(a);
    }
    int diameter = getDiameter(mp);
    int d[200001] = {0, };
    d[0] = -1;
    for (int i = 1; i <= diameter; i++) {
        d[i] = d[i - 1] == -1 ? 1 : -1;
        if (i > 2 && d[i] != 1) {
            d[i] = d[i - 2] == -1 ? 1 : -1;
        }
    }
    if (d[diameter] == 1) {
        cout << "First";
    } else cout << "Second";
    return 0;
}
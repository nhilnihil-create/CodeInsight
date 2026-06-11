#include <bits/stdc++.h>
#define WHOLE(v) (v).begin(), (v).end()
#define REV_WHOLE(v) (v).rbegin(), (v).rend()
using i64 = int64_t;
using namespace std;
template<typename T> using rev_priority_queue = priority_queue<T, vector<T>, greater<T>>;
template<typename T> using vector2d = vector<vector<T>>;
template<class S, class T> void map_init(map<S, T> &m, S k, T v){if(!m.count(k)) m[k] = v;}
void R_YESNO(bool p) { cout << (p ? "YES" : "NO") << endl; }
void R_YesNo(bool p) { cout << (p ? "Yes" : "No") << endl; }
int main() {
    int N;
    cin >> N;
    vector<set<int>> edge(N);
    for(int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edge[a].insert(b), edge[b].insert(a);
    }
    int v = 0;
    vector<int> dist;
    for (int j = 0; j < 2; j++) {
        dist = vector<int>(N, -1);
        queue<pair<int, int>> q;
        q.push({v, 0});
        while(q.size()) {
            int x, d;
            tie(x, d) = q.front(); q.pop();
            dist[x] = d;
            for (auto y : edge[x]) {
                if (dist[y] >= 0) continue;
                q.push({y, d + 1});
            }
        }
        v = distance(dist.begin(), max_element(WHOLE(dist)));
    }
    int D = *max_element(WHOLE(dist));
    cout << (D % 3 != 1 ? "First" : "Second") << endl;
    return 0;
}
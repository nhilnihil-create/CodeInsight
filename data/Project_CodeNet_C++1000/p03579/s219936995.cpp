#include <bits/stdc++.h>
#define WHOLE(v) (v).begin(), (v).end()
#define REV_WHOLE(v) (v).rbegin(), (v).rend()
using i64 = int64_t;
using namespace std;
template<typename T> using rev_priority_queue = priority_queue<T, vector<T>, greater<T>>;
template<class S, class T> void map_init(map<S, T> &m, S k, T v){if(!m.count(k)) m[k] = v;}
void R_YESNO(bool p) { cout << (p ? "YES" : "NO") << endl; }
void R_YesNo(bool p) { cout << (p ? "Yes" : "No") << endl; }
int main() {
    i64 N, M;
    cin >> N >> M;
    i64 ans = 0;
    vector<set<int>> edge(N);
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edge[a].insert(b);
        edge[b].insert(a);
    }
    vector<int> color(N, -1);
    queue<int> q;
    q.push(0);
    color[0] = 0;
    while(q.size()) {
        int a = q.front();
         q.pop();
        for(auto b : edge[a]) {
            if(color[b] < 0) {
                color[b] = !color[a];
                q.push(b);
            } else if (color[b] == color[a]) {
                ans = (N * (N - 1)) / 2 - M;
                cout << ans << endl;
                return 0;
            }
        }
    }
    i64 A = 0, B = 0;
    for(int i = 0; i < N; i++) {
        if(color[i]) A++;
        else B++;
    }
    ans = A * B - M;
    cout << ans << endl;
    return 0;
}
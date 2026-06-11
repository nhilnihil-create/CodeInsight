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
    int N;
    cin >> N;
    vector<set<int>> edge(N);
    vector<int> c(N);
    for(int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edge[a].insert(b);
        edge[b].insert(a);
    }
    for(auto &x : c) cin >> x;
    sort(REV_WHOLE(c));
    cout << accumulate(WHOLE(c), -c[0]) << endl;
    vector<i64> ans(N);
    queue<pair<int, int>> q;
    q.push({0, 0});
    int j = 0;
    while(q.size()) {
        int prev, cur;
        tie(cur, prev) = q.front(); q.pop();
        ans[cur] = c[j];
        for(auto next : edge[cur]) {
            if(next == prev) continue;
            q.push({next, cur});
        }
        j++;
    }
    for(int i = 0; i < N; i++) {
        cout << (i ? " " : "") << ans[i];
    }
    cout << endl;
    return 0;
}
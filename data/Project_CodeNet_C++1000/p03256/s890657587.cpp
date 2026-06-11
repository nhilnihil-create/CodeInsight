#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define p_ary(ary,a,b,i) do { cout << "["; for (int (i) = (a);(i) < (b);++(i)) cout << ary[(i)] << ((b)-1 == (i) ? "" : ", "); cout << "]\n"; } while(0)
#define p_map(map,it) do {cout << "{";for (auto (it) = map.begin();;++(it)) {if ((it) == map.end()) {cout << "}\n";break;}else cout << "" << (it)->first << "=>" << (it)->second << ", ";}}while(0)

vector<vector<int>> edges(200010);
vector<bool> used(200010,false);
vector<P> cnt(200010,P(0,0));

int main() {
    int n,m;
    string s;
    unordered_set<int> st;
    cin >> n >> m >> s;
    for (int i = 0;i < m;++i) {
        int u,v;
        cin >> u >> v;
        u--;v--;
        edges[u].push_back(v);
        if (u != v) edges[v].push_back(u);
    }
    for (int i = 0;i < n;++i) {
        for (int& j : edges[i]) {
            if (s[j] == 'A') cnt[i].first++;
            else cnt[i].second++;
        }
        if (cnt[i].first == 0 || cnt[i].second == 0) {
            st.insert(i);
            used[i] = true;
        }
    }
    while (!st.empty()) {
        unordered_set<int> next_st;
        for (auto& it : st) {    
            if (s[it] == 'A') for (int& i : edges[it]) cnt[i].first--;
            else for (int& i : edges[it]) cnt[i].second--;
        }
        for (auto& it : st) {
            for (int& i : edges[it]) if (i != it && !used[i]) {
                if (cnt[i].first == 0 || cnt[i].second == 0) {
                    next_st.insert(i);
                    used[i] = true;
                }
            }
        }
        st.clear();
        st = next_st;
    }
    bool ans = false;
    for (int i = 0;i < n;++i) if (cnt[i].first && cnt[i].second) ans = true;
    cout << (ans ? "Yes" : "No") << endl;
    return 0;
}
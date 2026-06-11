#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();

int main() {
    int n, C, s, t, c;
    cin >> n >> C;
    int ans = 0;
    unordered_map<int, vector<int>> rec;
    for(int i = 0; i < n; i++) {
        cin >> s >> t >> c;
        rec[c].push_back(s);
        rec[c].push_back(t);
    }
    map<int, int> rec2;
    for(auto p: rec) {
        auto& vec = p.second;
        sort(vec.begin(), vec.end());
        vector<int> st;
        for(int i = 0; i < vec.size(); i++) {
            if (!st.empty() && vec[i] == st.back()) {
                st.pop_back();
            } else {
                st.push_back(vec[i]);
            }
        }
        for(int i = 0; i < st.size(); i+= 2) {
            rec2[st[i]-1] += 1;
            rec2[st[i+1]] -= 1;
        }
    }
    int cur = 0;
    for(auto p: rec2) {
        cur += p.second;
        ans = max(ans, cur);
    }
    cout << ans << endl;
    return 0;
}



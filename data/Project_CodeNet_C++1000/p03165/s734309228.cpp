#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
const long long inf = 1LL << 60;
vector<long long> IL(int n) {
    vector<long long> vec(n);
    for (int i=0; i<vec.size(); i++) cin >> vec.at(i);
    return vec;
}
vector<string> IS(int n) {
    vector<string> vec(n);
    for (int i=0; i<vec.size(); i++) cin >> vec.at(i);
    return vec;
}

void PA(vector<long long> vec) {
    for (int i=0; i<vec.size()-1; i++) cout << vec.at(i) << " ";
    cout << vec.at(vec.size()-1) << endl;
    return;
}
map<long long, long long> CL(vector<long long> vec) {
    map<long long, long long> count;
    for (long long x: vec) {
        count[x] += 1;
    }
    return count;
}

map<string, long long> CS(vector<string> vec) {
    map<string, long long> count;
    for (string s : vec) {
        count[s] += 1;
    }
    return count;
}


int main() {
    using ll = long long;
    using vl = vector<long long>;


    string s, t; cin >> s >> t;

    vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1));

    for (int i=0; i<s.size(); i++) {
        for (int j=0; j<t.size(); j++) {
            if (s[i] == t[j]) {
                dp[i+1][j+1] = dp[i][j]+1;
            }
            else {
                dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
    }

    string ans;
    vector<long long> zahyo = {s.size(), t.size()};
    int now = dp[s.size()][t.size()];

    while (now != 0) {
        while (dp[zahyo[0]-1][zahyo[1]] == now) zahyo[0]--;
        while (dp[zahyo[0]][zahyo[1]-1] == now) zahyo[1]--;
        ans += s[zahyo[0]-1];
        now--; zahyo[0]--; zahyo[1]--;
    }

    reverse(ans.begin(), ans.end());
    cout << ans << endl;



}

#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}



 
int main() {
    int n, x;
    cin >> n >> x;
    vector<vector<int>> p(n, vector<int>(3));
    for (int i = 0; i < n; i++) {
        int s, t, c;
        cin >> s >> t >> c;
        p.at(i) = vector<int>{s, t, c};
    }
    sort(begin(p), end(p));
    vector<pair<int, int>> r(30);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 30; j++) {
            if (p.at(i).at(0) > r.at(j).second || p.at(i).at(2) == r.at(j).first) {
                r.at(j) = make_pair(p.at(i).at(2), p.at(i).at(1));
                chmax(ans, j + 1);
                break;
            } 
        }
    }
    cout << ans << endl;
    return 0;
}
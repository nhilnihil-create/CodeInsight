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


    

    int n; cin >> n;
    vector<vector<int>> h(n+1, vector<int>(3));
    vector<vector<int>> dp(n+1, vector<int>(3));

    for (int i=1; i<n+1; i++) {
        for (int j=0; j<3; j++) {
            int a=0; cin >> a;
            h[i][j] = a;
        }
    }

    set<int> st = {0, 1, 2};

    for (int i=0; i<n; i++) {
        for (int j=0; j<3; j++) {
            switch (j)
            {
            case 0:
                dp[i+1][j] = max(dp[i][1], dp[i][2]) + h[i+1][j];
                break;
            case 1:
                dp[i+1][j] = max(dp[i][0], dp[i][2]) + h[i+1][j];
                break;
            default:
                dp[i+1][j] = max(dp[i][0], dp[i][1]) + h[i+1][j];
                break;
            }
        }
    }

    int ans = *max_element(dp[n].begin(), dp[n].end());
    cout << ans << endl;




}

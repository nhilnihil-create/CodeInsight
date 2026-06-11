#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
    vector<int> A(3);
    rep(i,3) cin >> A[i];

    vector<vector<int>> order = {{0,1,2}, {1,2,0}, {2,1,0}, {0,2,1}, {2,1,0}, {1,0,2}};
    int ans = 10e5;
    rep(i,6) {
        int tmp = abs(A.at(order.at(i).at(1)) - A.at(order.at(i).at(0))) + abs(A.at(order.at(i).at(2)) - A.at(order.at(i).at(1)));
        ans = min(ans, tmp);
    }
    cout << ans << endl;
} 

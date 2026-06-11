#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
    int N, M;
    cin >> N >> M;
    vector<int> L(M), R(M);
    rep(i,M) cin >> L.at(i) >> R.at(i);
    sort(L.begin(), L.end(), greater<int>());
    sort(R.begin(), R.end());
    cout << max(0, R.at(0) - L.at(0) + 1) << endl;
}

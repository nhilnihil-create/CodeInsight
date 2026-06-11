#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main() {
    vector<int> N(5);
    rep(i, 5) cin >> N[i];
    int k;
    cin >> k;

    sort(N.begin(), N.end());
    if (N[4] - N[0] > k) cout << ":(" << endl;
    else cout << "Yay!" << endl;
}
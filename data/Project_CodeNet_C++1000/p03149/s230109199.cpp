#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

int main() {
    vector<int> n(4);
    rep(i, 4) cin >> n[i];

    sort(n.begin(), n.end());

    vector<int> v = {1, 4 ,7, 9};
    cout << (n == v ? "YES" : "NO") << endl;
    
    return 0;
}
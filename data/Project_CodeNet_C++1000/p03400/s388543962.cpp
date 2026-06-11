#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N = 0, D, X;
    cin >> N >> D >> X;
    vector<int> A(N,0);
    int ans = 0;
    for(int i = 0; i < N; i++) {
        cin >> A.at(i);
        ans++;
        ans += (D - 1)/A.at(i);
    }
    cout << ans + X << endl;

    return 0;
}
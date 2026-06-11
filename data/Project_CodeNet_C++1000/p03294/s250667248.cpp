#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N = 0;
    cin >> N;
    vector<int> A(N,0);
    ll ans = -1*N;
    for(int i = 0; i < N; i++) {
        cin >> A.at(i);
        ans += A.at(i);
    }
    cout << ans << endl;


    return 0;
}
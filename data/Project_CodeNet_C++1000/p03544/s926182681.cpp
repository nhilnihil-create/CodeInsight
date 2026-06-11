#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;

int main() {
    int N;
    cin >> N;
    vector<ll> L(87);

    L.at(0) = 2;
    L.at(1) = 1;
    for (int i = 2; i <= N; i++) {
        L.at(i) = L.at(i - 1) + L.at(i - 2);
    }

    cout << L.at(N) << endl;

    return 0;
}

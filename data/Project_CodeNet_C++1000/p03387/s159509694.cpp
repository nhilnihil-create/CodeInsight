#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;
const ll C = 1e9+7;

int main() {
    vector<int> N(3);
    cin >> N[0] >> N[1] >> N[2];

    sort(N.begin(), N.end());
    ll div = N[2] - N[1] + N[2] - N[0];

    if(div % 2 == 0) {
        cout << div / 2 << endl;
    }
    else {
        cout << div / 2 + 2 << endl;
    }
}
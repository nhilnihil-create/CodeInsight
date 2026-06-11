#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;
const ll C = 1e9+7;

int main() {
    ll N, M;
    cin >> N >> M;
    cout << (1900 * M + (N-M) * 100) * pow(2, M) << endl;
}
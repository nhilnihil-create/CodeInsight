#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;
const ll C = 1e9+7;

int main() {
    ll N, M;
    cin >> N >> M;
    if(N == 1 && M == 1) cout << 1 << endl;
    if(N == 1 && M >= 2) cout << M - 2 << endl;
    if(M == 1 && N >= 2) cout << N - 2 << endl;
    if(N >= 2 && M >= 2) cout << N * M - (N * 2 + M * 2 - 4) << endl;
}
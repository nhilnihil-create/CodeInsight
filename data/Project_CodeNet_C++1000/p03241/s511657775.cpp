#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 1LL << 60;
const ll mod = 1e9 + 7;

int main() {
    ll N, M;
    cin >> N >> M;
    ll tmp = M / N;
    for(int i = tmp; i > 0; i--) {
        ll amari = M - i * N;
        if(amari % i == 0) {
            cout << i << "\n";
            return 0;
        }
    }
    cout << 0 << "\n";
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;
const ll C = 1e9+7;

int main() {
    int N, Y, k;
    cin >> N >> Y;

    for(int i=0; i<=N; i++) {
        for(int j=0; i+j<=N; j++) {
            k = N - i - j;
            if(10000 * i + 5000 * j + 1000 * k == Y) {
                cout << i << " " << j << " " << k << endl;
                return 0;
            }
        }
    }
    cout << -1 << " " << -1 << " " << -1 << endl;
}
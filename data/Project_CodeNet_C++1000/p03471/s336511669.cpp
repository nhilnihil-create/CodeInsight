#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

int main() {
    ll N, Y;
    cin >> N >> Y;


    for(int i=0; i<=N; i++) {
        for(int j=0; j<=N-i; j++) {
            int k = N - i - j;
            if(i * 1000 + j * 5000 + k * 10000 == Y) {
                cout << k << " " << j << " " << i << endl;
                return 0;
            }
        }
    }
    cout << -1 << " " << -1 << " " << -1 << endl;
}
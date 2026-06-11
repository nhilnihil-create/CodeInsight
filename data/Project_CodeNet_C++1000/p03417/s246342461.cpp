#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, M;
    cin >> N >> M;

    if(N == 1 && M == 1) {
        cout << 1 << endl;
        return 0;
    }

    if(N == 1 || M == 1) {
        cout << N * M - 2LL << endl;
        return 0;
    }

    cout << N * M - 2LL * (N + M) + 4LL << endl;
}
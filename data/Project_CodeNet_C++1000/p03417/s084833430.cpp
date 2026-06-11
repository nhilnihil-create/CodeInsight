#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()

int main() {
    ll N, M;
    cin >> N >> M;
    if (N == 1) N = 3;
    if (M == 1) M = 3;
    cout << (N-2) * (M-2) << endl;
}

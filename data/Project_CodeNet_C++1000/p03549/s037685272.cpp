#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    int N, M;
    cin >> N >> M;
    cout << (100 * N + 1800 * M) * (1 << M) << "\n";
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Z, W;
    cin >> N >> Z >> W;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    cout << (N == 1 ? abs(W - a[N - 1])
                    : max(abs(W - a[N - 1]), abs(a[N - 1] - a[N - 2])))
         << endl;
}
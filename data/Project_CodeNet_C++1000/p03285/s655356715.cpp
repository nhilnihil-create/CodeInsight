#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

typedef long long ll;

int main() {
    int N;
    cin >> N;
    rep(i, N / 7 + 1) {
        if ((N - i * 7) % 4 == 0) {
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
}
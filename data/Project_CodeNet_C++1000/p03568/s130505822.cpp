#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    int N, A, ans = 1, ng = 1;
    cin >> N;
    rep(i, N) {
        ans *= 3;
        cin >> A;
        if (A % 2 == 0) {
            ng *= 2;
        }
    }
    cout << ans - ng << "\n";
}
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;

int A, B;

int main() {
    cin >> A >> B;

    if (B % A == 0) {
        printf("%d\n", A + B);
    } else {
        printf("%d\n", B - A);
    }
}
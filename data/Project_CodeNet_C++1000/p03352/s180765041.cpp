#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, n) for (int i = 1; i <= (n); i++)
using ll = long long;

bool ex[1001];

int main() {
    int X;
    cin >> X;
    ex[1] = true;
    for (int i = 2; i <= X; i++) {
        int a = i * i;
        while (a <= X) {
            ex[a] = true;
            a *= i;
        }
    }
    for (int i = X; i >= 1; --i) {
        if (ex[i]) {
            cout << i << endl;
            return 0;
        }
    }
}
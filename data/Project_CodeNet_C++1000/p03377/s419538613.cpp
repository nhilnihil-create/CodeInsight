#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    int A,B,X;
    cin >> A >> B >> X;
    if (A > X || A+B < X) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
}

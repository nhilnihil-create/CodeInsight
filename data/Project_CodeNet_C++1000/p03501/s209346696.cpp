#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    int N, A, B;
    cin >> N >> A >> B;
    if (A * N > B) {
        cout << B << endl;
    } else {
        cout << A * N << endl;
    }
}
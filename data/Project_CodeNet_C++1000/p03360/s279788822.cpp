#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {

    int A,B,C,K;
    cin >> A >> B >> C >> K;
    int Max = max({A, B, C});
    for (int i = 1; i <= K; i++) {
        Max = Max*2;
    }
    cout << Max + (A + B + C) - max({A, B, C}) << endl;
    return 0;
}
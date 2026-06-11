#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i <= (int)(n); i++)

int main() {
    int A, B, C, X, count = 0;
    cin >> A >> B >> C >> X;

    rep(i, min(A, (X / 500))){
        rep(j, min(B, ((X - (500*i)) / 100))){
            if (C >= (X - ((500*i)+(100*j))) / 50) {
                count++;
            }
        }
    }
    cout << count << endl;

    return 0;
}

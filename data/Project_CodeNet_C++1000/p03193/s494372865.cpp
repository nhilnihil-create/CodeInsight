#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, H, W, A, B, count = 0;
    cin >> N >> H >> W;
    for (int i = 0; i < N; i++) {
        cin >> A >> B;
        if (A >= H && B >= W) count++;
    }
    cout << count << endl;
    return 0;
}
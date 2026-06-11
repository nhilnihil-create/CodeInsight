#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int64_t N,M;
    cin >> N >> M;

    // どちらも1の場合 1
    if(N == 1) {
        if(M == 1) {
            cout << "1\n";
        } else {
            cout << M-2 << endl;
        }
    } else {
        if(M == 1) {
            cout << N-2 << endl;
        } else {
            cout << (N-2)*(M-2) << endl;
        }
    }
    //どちらかが1の場合、
    // 隅は2回、辺は3回=> 辺の数-2
    
    // どちらも2以上の場合
    // 隅は4回 辺は6回 中は9回

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

int main() {
    int N, count = 0;
    cin >> N;
    vector<long> A(N);
    for(int i=0; i<N; i++) cin >> A[i];
    bool flg = true;

    while (flg) {
        flg = false;
        for(int i=0; i<N; i++) {
            if(A[i] % 2 == 0 && flg == false) {
                A[i] /= 2;
                flg = true;
            }
            else {
                A[i] *= 3;
            }
        }
        if(flg) count++;
    }
    cout << count << endl;
}
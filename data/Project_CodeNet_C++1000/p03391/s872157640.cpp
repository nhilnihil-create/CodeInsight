#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

using namespace std;

int main(void) {
    int N;
    cin >> N;
    vector<int64_t> A(N), B(N);
    bool zero = true;
    for(int i=0; i<N; i++) {
        cin >> A[i] >> B[i];
        if(A[i] != B[i]) zero = false;
    }

    if(zero) {
        cout << 0 << endl;
    } else {
        int64_t ans = accumulate(A.begin(), A.end(), 0L);
        for(int i=0; i<N; i++) {
            if(A[i] <= B[i]) {
                B[i] -= A[i];
                A[i] = 0;
            }
        }
        int64_t tmp = numeric_limits<int64_t>::max();
        for(int i=0; i<N; i++) {
            if(A[i]) tmp = min(tmp, B[i]);
        }
        cout << ans - tmp << endl;
    }
    return 0;
}

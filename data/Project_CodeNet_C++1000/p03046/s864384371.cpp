#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main() {
    long long int M, K;
    cin >> M >> K;

    long long int TtoM = (1 << M);
    if (K > TtoM - 1 || (M == 1 && K == 1)) {
        cout << -1;
    } else if (K == 0){
        cout << 0 << " " << 0;
        for (int i = 1; i < TtoM; i++) {
            cout << " " << i << " " << i;
        }
    } else {
        vector<long long int> a(TtoM * 2);
        a[TtoM - 1] = K;
        a[TtoM * 2 - 1] = K;
        for (int i = 0; i < TtoM; i++) {
            if (i < K) {
                a[TtoM - 2 - i] = i;
                a[TtoM + i] = i;
            } else if (i > K) {
                a[TtoM - 1 - i] = i;
                a[TtoM + i - 1] = i;
            }
        }

        cout << a[0];
        for (int i = 1; i < TtoM * 2; i++) {
            cout << " " << a[i];
        }
    }
}
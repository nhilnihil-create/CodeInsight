#include <iostream>
using namespace std;

typedef long long ll;

ll mypow(int n, int a) {
    if (a == 0) {
        return 1;
    } else {    
        ll r = n;
        for (int i = 0; i < a - 1; i++) {
            r *= n;
        }
        return r;
    }
}

int main() {
    int M, K; cin >> M >> K;
    if (K >= mypow(2, M)) {
        cout << -1 << endl;
    } else if (M == 0) {
        cout << "0 0" << endl;
    } else if (M == 1 && K == 0) {
        cout << "1 1 0 0" << endl;
    } else if (M == 1 && K == 1) {
        cout << -1 << endl;
    } else {
        for (int i = 0; i < mypow(2, M); i++) {
            if (i != K) printf("%d ", i);
        }
        printf("%d ", K);
        for (int i = mypow(2, M) - 1; 0 <= i; i--) {
            if (i != K) printf("%d ", i);
        }
        printf("%d", K);
    }
}

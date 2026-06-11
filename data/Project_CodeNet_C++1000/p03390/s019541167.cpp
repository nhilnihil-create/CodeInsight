#include <iostream>
using namespace std;
typedef long long ll;
 
int main() {
    int Q;
    cin >> Q;
    for (int q = 0; q < Q; ++q) {
        ll A, B;
        cin >> A >> B;
        if (A >= B) {
            swap(A, B);
        }  // A < B
 
        ll ok = A, ng = B + 1;
        while (ng - ok > 1) {
            ll mid = (ok + ng) / 2;
 
            ll m = (mid + A) / 2;
            if (mid == A) --m;
            if (m * (A + mid - m) < A * B) {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        cout << ok + A - 2 << endl;
    }
    return 0;
}
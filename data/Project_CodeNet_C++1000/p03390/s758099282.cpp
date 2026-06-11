#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
    int Q;
    cin >> Q;

    while(Q--) {
        int64_t A, B;
        cin >> A >> B;
        int64_t s = (int64_t)sqrt(A*B);
        if(A == B) {
            cout << A+B-2 << endl;
        } else if(s*s == A*B) {
            cout << 2*s-3 << endl;
        } else if(s*(s+1) >= A*B) {
            cout << 2*s-2 << endl;
        } else {
            cout << 2*s-1 << endl;
        }
    }
    return 0;
}

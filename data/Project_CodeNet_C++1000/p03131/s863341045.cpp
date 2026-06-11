#include <iostream>
using namespace std;

typedef long long ll;

int main() {
    ll K, A, B;
    ll cookie = 1;
    ll yen = 0;
    bool change = false;
    double BperA;
    cin >> K >> A >> B;

    //BperA = (double)B / (double)A;
    for (int i = 0; i < K; i++) {
        if (change) {
            yen-=1;
            cookie += B;
            change = false;
            continue;
        }
        if (cookie < A) {
            cookie++;
        } else if (K-i >= 2 && cookie>=A && B-A > 2) {
            cookie -= A;
            yen+=1;
            change = true;
        } else {
            cookie++;
        }
    }
    cout << cookie << endl;
}

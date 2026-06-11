#include <iostream>
using namespace std;

int main() {
    int N, A, B;
    cin >> N >> A >> B;

    int total = 0;
    for (int n=1; n<=N; ++n) {
        int r = n;
        int sub = 0;
        while (r != 0) {
            sub += r % 10;
            r /= 10;
        }
        if (((A <= sub) && (sub <= B))) {
            total += n;
        }
    }
    cout << total << endl;
}

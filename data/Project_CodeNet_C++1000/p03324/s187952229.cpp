#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int D;
    int N;
    cin >> D;
    cin >> N;
    if (N == 100) {
        N++;
    }
    if (D == 0) {
        cout << N << endl;
        return 0;
    }
    int result = 0;
    int toDiv = pow(100, D);
    for (int i = 1, c = 0; c < N; i++) {
        int tmp = i % toDiv;
        if (tmp == 0) {
            result = i;
            c++;
        }
    }
    cout << result << endl;
}
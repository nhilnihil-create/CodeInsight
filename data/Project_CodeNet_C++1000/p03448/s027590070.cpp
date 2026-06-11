#include <iostream>
using namespace std;

bool is_equal_number(int i, int j, int k, int X) {
    if (500 * i + 100 * j + 50 * k == X) {
        return true;
    }
    return false;
}

int main() {
    int A, B, C;
    int X;
    cin >> A >> B >> C >> X;

    int counter = 0;
    for (int i = 0; i <= A; ++i) {
        for (int j = 0; j <= B; ++j) {
            for (int k = 0; k <= C; ++k) {
                if (is_equal_number(i, j, k, X)) {
                    ++counter;
                }
            }
        }
    }

    cout << counter << endl;
}
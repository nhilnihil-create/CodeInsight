#include <iostream>
using namespace std;

int main() {
    int N, A, B;
    cin >> N >> A >> B;
    if ((B - A) == 1) {
        cout << "Borys" << endl;
        return 0;
    }

    while (true) {
        // Alice
        if (A + 1 < B) {
            ++A;
        }
        if ((B - A) == 1) {
            cout << "Alice" << endl;
            return 0;
        }

        if (A < B - 1) {
            --B;
        }
        if ((B - A) == 1) {
            cout << "Borys" << endl;
            return 0;
        }
    }

}

#include <iostream>
using namespace std;

int main() {
    int N;
    int i = 0;

    int sum = 0;

    cin >> N;

    for (i = 0; i < N; i++) {
        string x;
        cin >> x;

        if (x == "Y") {
            sum += 1;
        }
    }

    if (sum == 0) {
        cout << "Three" << endl;
    }
    else {
        cout << "Four" << endl;
    }

}
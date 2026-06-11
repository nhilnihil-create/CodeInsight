#include <iostream>

using namespace std;

int main() {
    int d[5];
    for (int i = 0; i < 5; i++) {
        int temp;
        cin >> temp;
        d[i] = temp;
    }
    int k;
    cin >> k;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < i; j++) {
            if (d[i] - d[j] > k) {
                cout << ":(";
                return 0;
            }
        }
    }
    cout << "Yay!";
    return 0;
}

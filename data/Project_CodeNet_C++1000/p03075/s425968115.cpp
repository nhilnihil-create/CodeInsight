#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int v[5], k;
    for (int i = 0; i < 5; i++) {
        cin >> v[i];
    }
    cin >> k;

    int sub = v[4] - v[0];
    
    if (sub > k) {
        cout << ":(" << endl;
    }
    else {
        cout << "Yay!" << endl;
    }

    return 0;
}
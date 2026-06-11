#include <iostream>
using namespace std;

int main() {
    int x[100], y[100], a[3][3];
    x[0] = 0;

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> a[i][j];
        }
    }

    for(int i = 0; i < 3; i++) {
        y[i] = a[0][i] - x[0];
    }

    for(int i = 0; i < 3; i++) {
        x[i] = a[i][0] - y[0];
    }
    
    bool good = true;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(x[i] + y[j] != a[i][j]) {
                good = false;
            }
        }
    }
    if(good) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <iomanip>
#include <queue>


using namespace std;

int main() {
    int X, max = 1;

    cin >> X;


    if (X > 1) {
        for (int i = 2; i <= 31; i++) {
            for (int j = 2; pow(i, j) <= X; j++) {
                if (pow(i, j) > max) {
                    max = pow(i, j);
                }
            }
        }
    }
    cout << max;

}


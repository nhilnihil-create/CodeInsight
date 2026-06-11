#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <cmath> 
#include <cctype>

using namespace std;

int main() {
    int a, b, sum;
    cin >> a >> b;
    int A[999];
    for (int i = 1; i <= 999; i++) {
        if (i == 1) {
            A[i - 1] = i;
            sum = i;
        } else {
            sum += i;
            A[i - 1] = sum;
        }
    }

    for (int i = 1; i < 999; i++) {
        if ((A[i] - A[i - 1]) == (b - a)) {
            cout << A[i] - b << endl;
            return 0;
        }
    }
}
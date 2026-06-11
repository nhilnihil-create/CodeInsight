#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>

using namespace std;

int get(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }

    return sum;
}

int main() {
    int A, B, N;
    int min = 1000000;
    cin >> N;
    for (A = 1; A <= N / 2; A++) {
        B = N - A;
        int sum   = get(A) + get(B);
        if (sum < min) {
            min = sum;
        }
    }
    cout << min << endl;
    
    return 0;
}
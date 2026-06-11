#include <iostream>

using namespace std;

int main() {
    int A, B, K;
    int divisors_found = 0;

    cin >> A >> B >> K;
    int divisor = min(A, B) + 1;
    
    while (divisors_found < K) {
        divisor--;
        if (A % divisor == 0  && B % divisor == 0)
            divisors_found++;
    }

    cout << divisor << endl;

    return 0;
}
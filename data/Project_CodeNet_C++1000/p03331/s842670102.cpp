#include <iostream>
using namespace std;
const int INF = 1 << 30;

int sumOfDigits(int x) {
    int sum = 0;
    while(x > 0) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}


int main() {

    int N;
    cin >> N;

    int thresh = N / 2 + 1;
    int sumMin = INF;

    for (int a=1; a<=thresh; ++a) {
        int b = N - a;
        if (b <= 0) continue;

        int suma = sumOfDigits(a);
        int sumb = sumOfDigits(b);
        int sum = suma + sumb;
        if (sum < sumMin) {
            sumMin = sum;
        }
    }
    cout << sumMin << endl;
}

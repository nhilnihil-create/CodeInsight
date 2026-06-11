#include <iostream>
using namespace std;

int main (void) {
    int a, b;
    cin >> a >> b;

    int sum, minus, product;
    sum = a+b, minus = a-b, product = a*b;

    int max;
    max = sum;
    if (max < minus) {
        max = minus;
    }
    if (max < product) {
        max = product;
    }

    int ans;
    ans = max;

    cout << ans << endl;
}
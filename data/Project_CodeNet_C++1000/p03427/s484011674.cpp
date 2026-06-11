#include <iostream>
using namespace std;
int main() {
    long long n;
    cin >> n;
    int result = 0;
    while (n > 0) {
        if ((n%10 != 9) && n>9) {
            result += 9;
            n = (n/10) - 1;
        } else {
            result += n%10;
            n /= 10;
        }
    }
    cout << result << endl;
}

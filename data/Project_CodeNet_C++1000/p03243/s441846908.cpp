#include <iostream>
using namespace std;
bool ok(int n) {
    int a = n % 10;
    n /= 10;
    int b = n % 10;
    n /= 10;
    int c = n % 10;
    return (a == b && b == c);
}
int main(void) {
    int N;cin>>N;
    for (int i = N; i <= 999; i++) {
        if (ok(i)) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}
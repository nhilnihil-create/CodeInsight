#include <iostream>
using namespace std;
int main() {
    long long n, a[5];
    cin >> n;
    long long minA = n;
    for (int i = 0; i<5; i++) {
        cin >> a[i];
        minA = min(minA, a[i]);
    }
    cout << 5 + (n-1)/minA << endl;
}
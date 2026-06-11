#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin >> n;

    int sum = 0, t = n;
    while (t != 0) {
        sum += t % 10;
        t /= 10;
    }

    cout << (n%sum==0 ? "Yes" : "No") << endl;
    return 0;
}
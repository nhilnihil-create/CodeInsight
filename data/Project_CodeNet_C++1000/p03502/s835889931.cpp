#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int f = 0;
    cin >> n;
    for (int i = n; i > 0; i /= 10) {
        f += i % 10;
    }
    if (n % f == 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
}
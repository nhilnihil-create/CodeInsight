#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int i = 1;
    while (1) {
        if (i*i <= n)
            i++;
        else {
            cout << (i-1)*(i-1) << endl;
            return 0;
        }
    }
}
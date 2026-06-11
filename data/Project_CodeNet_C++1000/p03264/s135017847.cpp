#include <bits/stdc++.h>
using namespace std;

int calc(int, int);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k;
    cin >> k;
    int n = 1;
    int odd = 0;
    int even = 0;
    while (n <= k) {
        if (n % 2 == 0) {
            even++;
        } else {
            odd++;
        }
        n++;
    }
    cout << odd * even;
}
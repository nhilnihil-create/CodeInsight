#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int N, div, dig_sum = 0;
    cin >> N;
    div = N;

    while (div > 0) {
        dig_sum += div % 10;
        div = div / 10;
    }
    if (N % dig_sum)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
}
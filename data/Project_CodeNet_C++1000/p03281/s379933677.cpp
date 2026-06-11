#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    int cnt = 0;
    for (int i = 1; i <= N; i += 2) {
        int divisors = 0;
        for (int k = 1; k <= i; k++) {
            if (i % k == 0) divisors++;
        }
        if (divisors == 8) cnt++;
    }
    cout << cnt << endl;
}
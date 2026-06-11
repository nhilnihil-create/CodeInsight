#include <bits/stdc++.h>
using namespace std;

long N, ans;

int main(void) {

    cin >> N;
    for (long i = 1; i <= N; i+=2) {
        long count = 0;
        for (long j = 1; j <= i; j++) {
            if (i % j == 0) count++;
        }

        if (count == 8) ans++;
    }

    cout << ans << endl;

    return 0;

}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
int a[110];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> a[i];

    double avr = 0;
    for (int i = 0; i < N; i++) avr += (double)a[i];
    avr /= (double)N;

    int ans = 0;
    double min_abs = 1.0e9;
    for (int i = 0; i < N; i++) {
        if (abs(a[i] - avr) < min_abs) {
            min_abs = abs(a[i] - avr);
            ans = i;
        }
    }    

    cout << ans << endl;

    return 0;
}

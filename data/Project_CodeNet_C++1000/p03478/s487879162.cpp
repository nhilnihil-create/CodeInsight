#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        int sum = 0;
        for(int j = 1; j <= i; j *= 10) {
            int d = i % (j * 10) / j;
            sum += d;
        }

        if(sum >= a && sum <= b) {
            ans += i;
        }
    }
    cout << ans << endl;
    
    return 0;
}
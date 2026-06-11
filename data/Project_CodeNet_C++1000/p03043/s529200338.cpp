#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N, K;
    cin >> N >> K;

    double ans = (N - K + 1)*(N - K + 1 > 0);
    //cout << ans << endl;
    for(int i = 1; i < min(N + 1, K); i++) {
        //cout << ans << endl;
        for(int j = 0; j < 30; j++) {
            if(i*(ll)pow(2, j) >= (ll)K) {
                ans += pow(2, -1*j);
                break;
            }
        }
        //cout << ans << endl;
    }

    cout << fixed << setprecision(15) << (double)ans/(double)N << endl;


    return 0;
}
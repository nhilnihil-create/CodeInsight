#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int INF = 100000000;

int main() {
    int A, B, K;
    int ans;
    cin >> A >> B >> K;

    int cnt = 0;
    for (int i = min(A, B); i >= 1; i--) {
        if (A % i == 0 && B % i == 0) {
            cnt++;
        }
        if (cnt == K) {
            ans = i;
            break;
        }
    }

    cout << ans << endl;
}

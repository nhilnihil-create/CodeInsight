#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

int N, K;

int main() {
    cin >> N >> K;
    vector<long long> s(N + 1, 0);
    long long a;
    for (int i = 0; i < N; i++) {
        cin >> a;
        s[i + 1] = s[i] + a;
    }
    
    long long t, b, ans = 0;
    int cnt;
    for (int k = 0; k < 41 ; k++) {
        b = 1LL << (40 - k);
        ans += b;
        cnt = 0;
        for (int i = 0; i < N; i++) {
            for (int j = i; j < N; j++) {
                t = s[j + 1] - s[i];
                if ((ans & t) == ans) {
                    ++cnt;
                }
            }
        }
        if (cnt < K) {
            ans -= b;
        }
    }
    cout << ans << endl;
}

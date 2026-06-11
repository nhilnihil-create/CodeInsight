#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    string S;
    cin >> S;
    int N = S.size();
    int ans = 0;
    int a = 0, b = 0;
    for(int i = 0; i < N; i++) {
        if(S[i] - '0' ^ i%2) {
            a++;
        }

        if(S[i] - '0' ^ (1 + i)%2) {
            b++;
        }
    }
    ans = min(a, b);
    cout << ans << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main() {
    int K;
    cin >> K;
    int ans = 0;
    for (int i = 1; i <= K; i++){
        for (int j = i + 1; j <= K; j++){
            if ((i + j) % 2) ans++;
        }
    }
    cout << ans << endl;
}

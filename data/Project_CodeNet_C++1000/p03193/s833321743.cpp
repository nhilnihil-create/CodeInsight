#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

struct mypair {
    int A;
    int B;
};

int main() {
    int N, H, W;
    cin >> N >> H >> W;
    vector<struct mypair> Pair(N);

    for (int i = 0; i < N; i++)
        cin >> Pair.at(i).A >> Pair.at(i).B;
    
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (Pair.at(i).A >= H && Pair.at(i).B >= W) {
            ans++;
        }
    }

    cout << ans << endl;
}
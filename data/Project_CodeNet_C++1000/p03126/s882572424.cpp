#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> like(M,0);
    for(int i = 0; i < N; i++) {
        int K;
        cin >> K;
        for(int j = 0; j < K; j++) {
            int a;
            cin >> a;
            like.at(a-1)++;
        }
    }
    int ans = 0;
    for(int i = 0; i < M; i++) {
        if(like.at(i) == N) {
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}
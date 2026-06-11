#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M, cnt = 0; cin >> N >> M;
    vector<int> bucket(M+10, 0);
    for (int i = 0; i < N; i++) {
        int k; cin >> k;
        for (int j = 0; j < k; j++) {
            int a; cin >> a;
            bucket.at(a-1)++;
        }
    }
    for (int i = 0; i <= M; i++) {
        if (bucket.at(i) == N) cnt++;
    }
    cout << cnt << endl;
}
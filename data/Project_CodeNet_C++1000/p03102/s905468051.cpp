#include <bits/stdc++.h>

using namespace std;


int calc(vector<int> A, vector<int> B) {
    int ans = 0;
    for (int i = 0; i < A.size(); i++)
        ans += A[i] * B[i];
    return ans;
}

int main() {
    int N, M, C;
    cin >> N >> M >> C;
    vector<int> W(M);
    for (auto &&i: W) cin >> i;

    int ans = 0;
    for (int i = 0; i < N; i++) {
        vector<int> V(M);
        for (int j = 0; j < M; j++) {
            cin >> V[j];
        }
        if (calc(V,W) + C > 0 ){
            ans++;
        }
    }
    cout << ans << endl;
}
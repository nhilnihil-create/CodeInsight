#include <bits/stdc++.h>
using namespace std;
int main(){
    int64_t N, K;
    cin >> N >> K;
    vector<int64_t> ans(N+1, 0);
    int64_t fin = 0;
    for (int64_t b = K + 1; b <= N; b++){
        // N = p * b + r
        int64_t p = N / b;
        ans.at(b) += p * (b - K);
        int64_t r = N % b;
        if (K == 0) ans.at(b) += r;
        else if (r - K >= 0) ans.at(b) += (r - K) + 1;
        fin += ans.at(b);
    }
    cout << fin << endl;
}
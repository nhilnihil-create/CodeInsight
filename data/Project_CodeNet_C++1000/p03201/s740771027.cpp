#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    map<int64_t, int> A;
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        A[a]++;
    }

    int ans = 0;
    for (int64_t b = 1L << 31; b > 0; b >>= 1L){
        for (auto &a: A){
            auto k = a.first;
            auto v = a.second;
            if (A.count(b - k) == 0)
                continue;
            if (b - k == k){
                ans += A[k] / 2;
                A[k] = A[k] & 1;
                continue;
            }
            int mi = min(A[k], A[b - k]);
            ans += mi;
            A[k] -= mi;
            A[b - k] -= mi;
        }
    }

    cout << ans << endl;
}
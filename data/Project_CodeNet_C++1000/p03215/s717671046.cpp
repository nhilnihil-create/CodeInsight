#include <bits/stdc++.h>
using namespace std;
int main(void){
    int N, K;
    cin >> N >> K;
    vector<long long> A(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    
    for (int i = 1; i <= N; i++) {
        A[i] += A[i-1];
    }
    
    vector<long long> cans;
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j <= N; j++) {
            cans.push_back(A[j] - A[i]);
        }
    }

    for (int i = 0; i <= 60; i++) {
        long long bit = (1LL << (60 - i));
        vector<long long> next_cans;
        for (auto &j : cans) {
            if (bit & j) {
                next_cans.push_back(j);
            }
        }
        if (K <= next_cans.size()) {
            cans = next_cans;
        }
    }
    
    long long ans = cans[0];
    for (int i = 1; i < cans.size(); i++) {
        ans &= cans[i];
    }
    cout << ans << endl;
}

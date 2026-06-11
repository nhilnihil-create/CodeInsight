#include <bits/stdc++.h>
using namespace std;

bool ok(long long x, int K, vector<long long> &B) {
    int cnt = 0;
    for(long long num : B) {
        if((x & num) == x) ++cnt;
        if(cnt == K) return true;
    }
    return false;
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for(int i=0; i<N; ++i) cin >> A[i];
    vector<long long> B;
    B.reserve(N * (N + 1) / 2);
    for(int i=0; i<N; ++i) {
        long long sum = 0;
        for(int j=i; j<N; ++j) {
            sum += A[j];
            B.emplace_back(sum);
        }
    }

    long long res = 0;
    for(int b=50; b>=0; --b) {
        if(ok(res + (1LL << b), K, B)) res += (1LL << b); 
    }
    cout << res << endl;
}
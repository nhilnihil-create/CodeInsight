#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    long long N;
    cin >> N;
    
    vector<long long> D;
    for (long long i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            D.push_back(i);
            if (N / i != i) D.push_back(N / i);
        }
    }
    long long ans = 0;
    for (long long d : D) {
        long long m = N / d - 1;
        if (d < m) ans += m;
    }
    cout << ans << endl;
    return 0;
}

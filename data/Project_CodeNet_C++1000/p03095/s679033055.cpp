#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

constexpr int mod = 1e9 + 7;

int main() {
    int N;
    cin >> N;
    vector<char> S(N);
    rep(i, N) cin >> S[i];
    
    vector<int> alpha(26, 0);
    rep(i, N) ++alpha[S[i] - 'a'];
    long long ans = 1;
    rep(i, 26) ans = ans * (alpha[i] + 1) % mod;
    cout << ans - 1 << endl;
    return 0;
}

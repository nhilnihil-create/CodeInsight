// 互いに素なら N * M
// それ以外、少なくとも LCM(N, M)
// 対応する文字が同じなら OK
// それ以外は NG ？

#include<iostream>
#include<vector>
//#include<numeric>

using namespace std;

#define rep(i, n) for(long long i = 0;i < (n);i++)


long long gcd(long long a, long long b) {
    if (a < b) return gcd(b, a);
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}
// */

int main() {
    int N, M;
    string S, T;
    cin >> N >> M;
    cin >> S >> T;
    
    long long g = gcd(N, M);
    long long l = N / g * M;


    long long i = 0, j = 0;
    bool ok = true;
    while(i < N && j < M) {
        // cout << i << ", " << j << ": " << S[i] << ", " << T[j] << endl;
        if (S[i] != T[j]) ok = false;
        i += l / M;
        j += l / N;
    }

    if (ok) cout << l << endl;
    else cout << "-1" << endl;

    
    return 0;
}

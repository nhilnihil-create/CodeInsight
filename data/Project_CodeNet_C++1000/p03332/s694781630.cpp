#include <iostream>
#include <vector>
using namespace std;
#define MOD 998244353

// 繰り返し二乗法
long long bipow(long long n, int m) {
    if (m == 0) return 1;
    if (m % 2 == 0) {
        n = (n * n) % MOD;
        return bipow(n, m / 2) % MOD;
    } else
        return (n * bipow(n, m - 1)) % MOD;
}

// fact_num[i] = i! % MOD
// fact_denpow[i] = (i**(MOD-2)) % MOD
// fact_den[i] = fact_denpow[i]! % MOD
// nCm = fact_num[n] * fact_den[m] * fact_den[n-m]
// で計算できる（MODを適切に取る）
// O(NlogN)
void set_table(int N, vector<long long> &fact_num, vector<long long> &fact_den){
    fact_num.resize(N+1, 0);
    fact_den.resize(N+1, 0);
    vector<long long> fact_denpow(N+1, 0);

    fact_num[0] = 1;
    for(int i=1; i<=N; i++) fact_num[i] = (fact_num[i-1] * i) % MOD;

    for(int i=0; i<=N; i++) fact_denpow[i] = bipow(i, MOD-2);
    fact_den[0] = 1;
    for(int i=1; i<=N; i++) fact_den[i] = (fact_den[i-1] * fact_denpow[i]) % MOD;
}

// mCn
long long comb(const vector<long long> &fact_num, const vector<long long> &fact_den, int m, int n){
    return ((fact_num[m] * fact_den[n]) % MOD * fact_den[m-n]) % MOD;
}

int main(){
    long long N, A, B, K;
    cin >> N >> A >> B >> K;

    vector<long long> fact_num, fact_den;
    set_table(N, fact_num, fact_den);

    long long ans = 0;
    for(int x=0; x<=N; x++){
        long long rem = K - A * x;
        if(rem < 0 || rem % B != 0) continue;
        long long y = rem / B;
        if(y > N) continue;
        long long tmpA = comb(fact_num, fact_den, N, x);
        long long tmpB = comb(fact_num, fact_den, N, y);
        ans += (tmpA * tmpB) % MOD;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}

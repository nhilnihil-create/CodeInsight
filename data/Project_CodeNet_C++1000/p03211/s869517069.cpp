#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <cmath>
#include <stack>
#include <map>
#include <iomanip>
using namespace std;

int64_t min(int64_t a,int64_t b) {
    if (a > b)
    {
        return b ;
    }else
    {
        return a ;
    }
}

const int MAX = 510000;
const int MOD = 1000000007;

int64_t fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}


int main(){
    string s ;
    cin >> s ;
    vector<int> a(s.size()) ;
    for (int i = 0; i < s.size(); i++)
    {
        a.at(i) = s.at(i) - '0' ;
    }
    int num = 0 ;
    int ans = 999 ;
    for (int i = 0; i < s.size() - 2; i++)
    {
        num = a.at(i) * 100 + a.at(i+1) * 10 + a.at(i+2) ;
        ans = min(ans,abs(num - 753)) ;
    }
    cout << ans << endl ;
        
}
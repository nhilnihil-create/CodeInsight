#include <bits/stdc++.h>
using namespace std;
 
const int64_t MOD = 1e9+7;
 
int64_t extgcd(int64_t a, int64_t b, int64_t& x, int64_t& y){
    int64_t d = a;
    if(b != 0){
        d = extgcd(b, a%b, y, x);
        y -= (a/b) * x;
    }else{
        x = 1; y = 0;
    }
    return d;
}
 
int64_t mod_inv(int64_t a){
    int64_t x, y;
    extgcd(a, MOD, x, y);
    return (MOD + x%MOD) % MOD;
}
 
void add(int64_t& a, int64_t b){
    a = (a+b+MOD) % MOD;
}
void mul(int64_t& a, int64_t b){
    a = a*b % MOD;
}
 
int main(){
    int i, j, k;
    int N;
    const int MAX = 100001;
    cin >> N;
    int64_t A[MAX];
    for(i=1; i<=N; i++) scanf("%lld", &A[i]);
 
    int64_t invsum[MAX];
    invsum[0] = 0;
    for(i=1; i<=N; i++){
        invsum[i] = (invsum[i-1] + mod_inv(i)) % MOD;
    }
 
    int64_t ans = 0;
    for(i=1; i<=N; i++){
        add(ans, A[i] * (invsum[i] + invsum[N+1-i] - 1) % MOD);
    }
    for(i=2; i<=N; i++) mul(ans, i);
    cout << ans << endl;
    return 0;
}
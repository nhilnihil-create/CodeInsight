#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
#include<string>
#include<math.h>
 
using namespace std;
typedef long long LL;

const int MAX = 100010;
const int MOD = 1000000007;

LL mod_pow(LL x,LL n){
    LL ret = 1;

    while(n){
        if(n & 1)ret = ret * x % MOD;
        x = x * x % MOD;
        n /= 2;
    }

    return ret;
}

LL inv(LL n){
    return mod_pow(n,MOD - 2);
}

LL fact(LL n){
    LL ret = 1;
    for(int i = 1;i <= n;i++){
        ret = ret * i % MOD;
    }
    return ret;
}

int main(){
    LL N;
    LL A[MAX];
    LL sum[MAX] = {0};
    LL ans = 0;

    cin >> N;
    for(int i = 0;i < N;i++){
        cin >> A[i];
    }

    for(int i = 1;i <= N;i++){
        sum[i] = (sum[i-1] + inv(i)) % MOD;
    }

    for(int i = 0;i < N;i++){
        ans += A[i] * (sum[i + 1] + sum[N - i] - sum[1]) % MOD;
    }

    cout << ans % MOD * fact(N) % MOD << endl;

    return 0;
}
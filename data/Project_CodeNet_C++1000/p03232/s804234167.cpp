#define _USE_MATH_DEFINES

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;

typedef pair<long long int, long long int> P;

long long int INF = 1e18;
long long int MOD = 1e9 + 7;

long long int rev_mod(long long int num){
	long long int pow_num = MOD - 2;
	long long int mod_num = MOD;
	long long int pow_cur = num;
	long long int ret = 1;
	while(pow_num > 0){
		if(pow_num % 2 == 1){
			ret *= pow_cur;
			ret %= mod_num;
		}
		pow_cur *= pow_cur;
		pow_cur %= mod_num;
		pow_num /= 2;
	}
	return ret;
}

long long int frac[110000];

int main(){
    int N;
    cin >> N;
    long long int FN = 1;
    frac[1] = 1;
    for(int i = 2; i <= N; i++){
        FN = FN * i;
        FN %= MOD;
        frac[i] = rev_mod(i);
        frac[i] += frac[i - 1];
        frac[i] %= MOD;
    }
    long long int ans = 0;
    for(int i = 1; i <= N; i++){
        long long int A;
        cin >> A;
        ans += A * FN % MOD * (frac[i] + frac[N - i + 1] - frac[1]);
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}
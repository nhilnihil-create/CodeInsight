#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <utility>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <climits>
#include <set>
#include <cmath>
#include <numeric>
#include <iomanip>

using namespace std;
long long A[100000];
const long long MOD = 1000000007;
long long power(long long m, long long n){
    long long res = 1;
    while(n > 0){
        if(n & 1) {
            res = (res * m) % MOD;
        }
        m = (m * m) % MOD;
        n >>= 1;
    }
    return res;
}

long long inverse(long long a){
    return power(a, MOD - 2);
}
int main(){
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }

    long long left_denom_sum = 0;
    long long right_denom_sum = 0;
    long long ans = 0;
    for(int i = 0; i < N; i++){
        right_denom_sum = (right_denom_sum + inverse(i + 1)) % MOD;
    }
    for(int i = 0; i < N; i++){
        ans = (ans + (((left_denom_sum + right_denom_sum) % MOD) * A[i]) % MOD) % MOD;
        left_denom_sum = (left_denom_sum + inverse(i + 2));
        right_denom_sum = ((right_denom_sum - inverse(N - i)) + MOD) % MOD;
    }
    for(int i = 0; i < N; i++){
        ans = (ans * (long long) (i + 1)) % MOD;
    }
    cout << ans << endl;
    return 0;
}

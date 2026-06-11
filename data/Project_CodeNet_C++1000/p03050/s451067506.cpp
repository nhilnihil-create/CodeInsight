#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

// Nをmで割った商と余りが等しい
// N mod m
// 8 3 2 2
// 8 7 1 1

// N = m * p + p
// N = (m+1) * p
// 8 = 1 * 8
// 8 = 2 * 4
// 素因数分解して大きい数からやっていく

/*  divisor(n)
    入力：整数 n
    出力：nのすべての約数
    計算量：O(√n)
*/
vector<long long> divisor(long long n) {
    vector<long long> ret;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }
    sort(ret.begin(), ret.end()); // 昇順に並べる
    return ret;
}

long long solve(long long N) {
    long long res = 0;
    vector<long long> nums = divisor(N);
    for (long long i=0; i<nums.size(); ++i) {
        long long m = N / nums[i];
        if (m > 2 && N / (m-1) == N % (m-1)) {
        	res += m - 1;
        }
    }
    
    return res;
}

int main() {
    long long N; cin>>N;
    cout << solve(N) << endl;
    return 0;
}

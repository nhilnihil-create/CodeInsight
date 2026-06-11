#include<iostream>
#include<iomanip>
#include<cstdio>

#include<vector>
#include<queue>
#include<set>
#include<map>
#include<string>

#include<algorithm>
#include<cmath>
#include<numeric>

using namespace std;
typedef long long ll;
template <class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return 1;} return 0;}
template <class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return 1;} return 0;}
const ll INF = 1e18+1;

/*
あるb(>= K+1)を固定すると
a % b >= K
なのは 
bn + b-1 , b-2,...., K なる数

このような数の範囲は

[K,.,b-1], [b+K,..,b+b-1], [2b+K,..,2b+b-1], ..[,N]

Nをbで割った商 * (b-K)個はぶち込める
残りはあまりの分

Nをbで割った商qとして
q*b+K ... N はぶち込める
*/

int main() {
    ll N, K; cin >> N >> K;
    if (K == 0) {
    cout << N * N << endl;
    return 0;
    }
    ll res = 0;
    for (int b = K+1; b <= N; b++) {
        ll q = N/b;
        res += q * (b-K);
        if (N % b >= K) {
            res += N % b - K + 1;
        }
        //cout << b <<" "<<  q << " " << q * (b-K) << " " << N - (q*b + K  - 1) << endl;
    }
    cout << res << endl;
    
}


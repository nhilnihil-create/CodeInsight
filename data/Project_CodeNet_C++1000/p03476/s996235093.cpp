#include<bits/stdc++.h>
#define ll long long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;
const long double EPS = 0.0000000001;
const long double PI = (acos(-1));
const int MOD = 1000000007;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

bool is_prime(long long N) {
    if (N == 1) return false;
    for (long long i = 2; i * i <= N; ++i) {
        if (N % i == 0) return false;
    }
    return true;
}

int main(){

    int q,l,r; cin >> q;
    vector<int> p(100001,0);
    vector<int> s(100001,0);
    vector<int> ans(q,0);

    for(int i = 1; i <= 100000; i ++){
        if(i%2 == 0) s[i] = s[i-1];
        else if(is_prime(i) && is_prime((i+1)/2)){
            s[i] = s[i-1] + 1;
        }else {
            s[i] = s[i-1];
        }

    }

    rep(i,q){

        cin >> l >> r;
        ans[i] = s[r] - s[l-1];
    }

    rep(i,q) cout << ans[i] <<  endl;

}
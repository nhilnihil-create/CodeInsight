#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1000000007LL;
long long GCD(long long a, long long b){return b == 0 ? a : GCD(b, a % b);}
long long fast_exp(long long base, long long exp, long long mod = MOD) {
    long long tot = 1;
    for(;exp > 0;exp >>= 1) {
       if((exp & 1) == 1) tot = tot * base % mod;
       base = base * base % mod;
    }
    return tot;
}
long long slow_mult(long long base, long long exp, long long mod = MOD) {
    long long tot = 0;
    for(;exp > 0;exp >>= 1) {
       if((exp & 1) == 1) tot = (tot + base) % mod;
       base = (base + base) % mod;
    }
    return tot;
}

int n, q, a;
string s;

long long solve(int k){

    long long d = 0, m = 0, dm = 0, tot = 0;

    for(int i = 0; i < n; ++i){
        if(s[i] == 'D') ++d;
        if(s[i] == 'M'){ ++m; dm += d; }
        if(s[i] == 'C') tot += dm;
        if(i >= k - 1){
            if(s[i - k + 1] == 'D'){--d; dm -= m;}
            if(s[i - k + 1] == 'M') --m;
        }
    }

    return tot;

}

int main(){

    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n >> s >> q;

    for(int i = 0; i < q; ++i){
        cin >> a;
        cout << solve(a) << "\n";
    }

    return 0;

}

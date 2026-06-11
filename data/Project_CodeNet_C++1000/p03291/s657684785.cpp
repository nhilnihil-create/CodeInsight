#include <bits/stdc++.h>

using namespace std;

const unsigned long long MOD = 1000000007LL;
long long GCD(long long a, long long b){return b == 0 ? a : GCD(b, a % b);}
long long fast_exp(long long base, long long exp) {
    long long tot = 1;
    for(;exp > 0;exp >>= 1) {
       if((exp & 1) == 1) tot = tot * base % MOD;
       base = base * base % MOD;
    }
    return tot;
}

int main(){

    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    long long tot = 0, a = 0, b = 0, c = 0, q = 1, INV = fast_exp(3, MOD - 2) % MOD;

    for(auto i : s){
        if(i == 'A'){
            ++a;
        } else if(i == 'B'){
            b += a;
        } else if(i == 'C'){
            c += b;
        } else {
            c += b * INV;
            b += a * INV;
            a += INV;
            q *= 3;
        }
        a %= MOD; b %= MOD; c %= MOD; q %= MOD;
    }

    cout << c * q % MOD << "\n";

    return 0;

}

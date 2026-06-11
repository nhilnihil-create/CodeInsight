#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007LL;

int main(){

    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string s;
    cin >> s;

    long long a = 0, b = 0, c = 0, q = 1, INV = 333333336;

    for(auto i : s){
        if(i == 'A'){
            ++a;
        } else if(i == 'B'){
            b += a;
        } else if(i == 'C'){
            c += b;
        } else {
            c += b * INV; b += a * INV; a += INV; q *= 3;
            if(q > MOD)
                q %= MOD;
        }
        if(a > MOD) a %= MOD;
        if(b > MOD) b %= MOD;
        if(c > MOD) c %= MOD;
    }

    cout << c * q % MOD << "\n";

    return 0;

}

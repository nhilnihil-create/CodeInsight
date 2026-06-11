#include<bits/stdc++.h>

using namespace std;
using ll = long long int;

int main(void) {
    constexpr ll MOD = 1e9 + 7;
    cout << fixed << setprecision(16);

    string s;
    cin >> s;
    ll n = s.size();

    ll o = 1, a = 0, ab = 0, abc = 0;
    for(auto &c: s) {
        ll po = o, pa = a, pab = ab, pabc = abc;
        switch(c) {
            case 'A':
                a+=po;
                break;
            case 'B':
                ab += pa;
                break;
            case 'C':
                abc += pab;
                break;
            case '?':
                abc *= 3;
                ab *= 3;
                a *= 3;
                o *= 3;

                abc += pab;
                ab += pa;
                a += po;
                break;
        }
        a %= MOD;
        ab %= MOD;
        abc %= MOD;
        o %= MOD;
    }
    cout << abc << endl;
}

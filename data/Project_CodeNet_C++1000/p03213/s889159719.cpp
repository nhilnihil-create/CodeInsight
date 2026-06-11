#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

#define MOD 1000000007

int main(void) {
    ll N;
    ll A = 0, B = 0, C = 0, D = 0, E = 0;
    map<ll, ll> m;
    cin >> N;
    for(ll i = N;i > 0;i--) {
        ll cur = i;
        for(ll j = 2;j <= i;j++) {
            while(cur % j == 0) {
                m[j]++;
                cur /= j;
            }
        }
    }
    for(auto &j: m) {
        if(j.second >= 74) A++;
        if(j.second >= 24) B++;
        if(j.second >= 2) C++;
        if(j.second >= 14) D++;
        if(j.second >= 4) E++;
    }
    cout << A + B * (C - 1) + D * (E - 1) + E * (E - 1) * (C - 2) / 2  << endl;
    return 0;
}

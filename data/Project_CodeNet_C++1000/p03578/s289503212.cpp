#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

#define MOD 1000000007

int main(void) {
    ll N, M;
    map<ll, ll> D;
    cin >> N;
    for(ll i = 0;i < N;i++) {
        ll temp;
        cin >> temp;
        D[temp]++;
    }
    cin >> M;
    for(ll i = 0;i < M;i++) {
        ll temp;
        cin >> temp;
        D[temp]--;
    }
    for(auto &i: D) {
        if(i.second < 0) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}

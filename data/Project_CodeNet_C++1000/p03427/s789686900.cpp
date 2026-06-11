#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

#define MOD 1000000007

int main(void) {
    string N;
    ll sum = 0;
    cin >> N;
    reverse(N.begin(), N.end());
    for(ll i = 0;i < N.size() - 1;i++) {
        if(N[i] != '9') {
            N[i + 1] -= 1;
            N[i] = '9';
        }
    }
    for(auto &c: N) sum += c - '0';
    cout << sum << endl;
    return 0;
}

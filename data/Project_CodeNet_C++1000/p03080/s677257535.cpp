#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
typedef vector<ll> vel;
typedef vector<str> ves;
#define REP(i, a, b) for (ll i = (ll)(a); i < (ll)(b); i++)
#define rep(i, b) REP(i, 0, b)
const ll cd = 1000000007;
const double pi = 3.14159265358979;

int main() {
    ll N;
    str s;
    cin >> N >> s;
    ll countr = 0, countb = 0;
    rep(i, N) {
        if(s.at(i) == 'R') {
            countr++;
        }
        else {
            countb++;
        }
    }
    if(countr > countb) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}
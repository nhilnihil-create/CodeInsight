#include<bits/stdc++.h>
using namespace std;
using ll = long long;

string s;

bool f1(ll a, ll b) {
    for (ll i = a;i < b;++i) {
        if (s[i] == '#' && s[i + 1] == '#')return false;
    }
    return true;
}

bool f2(ll a, ll b) {
    for (ll i = a;i <= b;++i) {
        if (s[i - 1] == '.' && s[i] == '.' && s[i + 1] == '.')return true;
    }
    return false;
}

int main() {
    ll n, a, b, c, d;
    cin >> n >> a >> b >> c >> d >> s;
    --a;--b;--c;--d;
    bool flag;
    if (c < d) {
        flag = f1(a, d);
    }
    else {
        flag = f1(a, c) && f2(b, d);
    }
    if (flag)cout << "Yes" << endl;
    else cout << "No" << endl;
}
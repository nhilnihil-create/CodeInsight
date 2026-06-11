#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, s, e) for (int i = (int)(s); i < (int)(e); i++)
#define _rep(i, n) for (int i = (int)(n - 1); i >= 0; i--)
#define _REP(i, e, s) for (int i = (int)(e - 1); i >= (int)(s); i--)

#define yes cout << "yes" << endl;
#define Yes cout << "Yes" << endl;
#define YES cout << "YES" << endl;

#define no cout << "no" << endl;
#define No cout << "No" << endl;
#define NO cout << "NO" << endl;

#define out(st) cout << st << endl;

#define ll long long
#define ull unsigned long long

ll gcd(ll a, ll b) {
    if (a < b) return gcd(b, a);
    ll r;
    while ((r = a % b)) {
        a = b;
        b = r;
    }
    return b;
}

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (abs(a - c) <= d || (abs(a - b) <= d && abs(b - c) <= d)) {
        Yes;
    } else {
        No;
    }
}
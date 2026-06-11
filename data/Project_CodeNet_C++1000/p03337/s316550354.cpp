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

#define ll long long
#define ull unsigned long long
#define vi vector<int>

const double PI = 3.14159265358979323846;

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
    int A, B;
    cin >> A >> B;
    cout << max(A + B, max(A - B, A * B)) << endl;
}

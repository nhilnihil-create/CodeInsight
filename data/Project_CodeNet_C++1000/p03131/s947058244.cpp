#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <map>
#include <cmath>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

#define rep(i, o) for (ll i = 0; i < (o);i++)
#define rep_s(i, o) for (int i = 1; i <= (o);i++)
#define REP(i,a,b)for(int i=(int)(a);(i)<(int)(b);i++)
#define NUM 1e5

typedef long long ll;
typedef unsigned long long ull;

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll c, ll d) { return c / gcd(c, d) * d; }


template<class T>
bool chmax(T &a, const T &b) { if (a < b) { return b; } return a; }

template<class T>
bool chmin(T &a, const T &b) { if (a > b) { a = b; return a; } return a; }

int main() {
    ll k, a, b; 
    cin >> k >> a >> b;

    ll ans = 0;
    // cout << b*(k/(a+1))+(k%(a+1)) << endl;
    // ll biscuit = 1; ll yen = 0;
    // rep(i, k) {
    //     if (yen == 1) { ans += b*yen; yen = 0; continue; }
    //     if (biscuit == a) { yen = 1; biscuit = 0; continue; }
    //     biscuit++; 
    //     // if (a+1 <= k) ans = max(k+1, b*(k/(a+1))+(k%(a+1)));
    //     // else ans = k+1;
    //     // cout << ans << endl;
    // }
    // cout << ((ans+biscuit > k+1) ? ans+biscuit : k+1) << endl;
    if (b-a <= 2) ans = k+1;
    else 
    { 
        ans += a;
        ans += (b-a) * ((k-a+1)/2);
        ans += (k-a+1)%2;
    }
    cout << ans << endl;
    return 0;
}
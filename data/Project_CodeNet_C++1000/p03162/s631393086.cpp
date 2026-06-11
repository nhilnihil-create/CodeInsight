#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <stack>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
#define MOD 1000000007
#define MOD2 998244353
using ll = long long;
typedef pair<ll, ll> P;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

/*def*/
ll dpa[100100];
ll dpb[100100];
ll dpc[100100];
ll n;
ll a, b, c;

int main() {
/*input*/
    cin >> n;

    rep(i, 100100){
        dpa[i] = LLONG_MIN;
        dpb[i] = LLONG_MIN;
        dpc[i] = LLONG_MIN;
        }
    dpa[0] = 0;
    dpb[0] = 0;
    dpc[0] = 0;

/*main貰うdp*/
    for(int i = 1; i <= n; i++){
        cin >> a >> b >> c;
        dpa[i] = max({dpa[i], dpb[i-1] + a, dpc[i-1] + a});
        dpb[i] = max({dpb[i], dpc[i-1] + b, dpa[i-1] + b});
        dpc[i] = max({dpc[i], dpa[i-1] + c, dpb[i-1] + c});
    }

/*output*/
/* for debug
    for(int i = 1; i<=n;i++){
        cout << dpa[i]<< " " << dpb[i]<< " " << dpc[i] << endl;
    }
*/
    cout << max({dpa[n], dpb[n], dpc[n]}) << endl;
    return 0;
}

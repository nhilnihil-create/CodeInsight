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
ll dp[100100];
ll n, h[100100];

int main() {
/*input*/
    cin >> n;
    rep(i, n){cin >> h[i];}

    rep(i, 100100){dp[i] = LLONG_MAX;}
    dp[0] = 0;

/*main配るdp*/
    rep(i, n-1){
        chmin(dp[i+1], dp[i] + abs(h[i+1] - h[i]));
        chmin(dp[i+2], dp[i] + abs(h[i+2] - h[i]));
    }

/*output*/
    cout << dp[n-1] << endl;
    return 0;
}

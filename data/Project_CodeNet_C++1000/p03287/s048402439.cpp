#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>

#define DIV 998244353

using namespace std;
using ll = long long;
using ldb = long double;

int main() {
    ll N, M; cin >> N >> M;
    map<ll,ll> cnt;
    ll total = 0.;
    for (int i = 0; i < N; i++) {
        ll a; cin >> a;
        total += a;
        cnt[total % M]++;
    }
    cnt[0]++;
    ll ans = 0;
    for (auto x:cnt) {
        //cout << x.first << " " << x.second << endl;
        ans += (x.second - 1) * x.second / 2;
    }
    cout << ans << endl;
}

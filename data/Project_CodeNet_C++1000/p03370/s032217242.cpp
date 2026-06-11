#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

ll m[100];

int main(){
    ll n, x, a = 0;
    cin >> n >> x;
    rep(i, n){
        cin >> m[i];
        a += m[i];
    }
    ll am = x - a;
    sort(m,m+n);
    ll ans = am / m[0];
    ans += n;
    cout << ans << endl;
}
   
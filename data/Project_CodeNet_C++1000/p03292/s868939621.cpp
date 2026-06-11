#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;

int main(){
    vector<ll> a(3);
    rep(i, 3) cin >> a[i];
    sort(a.begin(),a.end());
    ll cou = 0;
    cou += a[1] - a[0];
    cou += a[2] - a[1];
    cout << cou << endl;
}
   
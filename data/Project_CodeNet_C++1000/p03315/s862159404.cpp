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
    ll ans = 0;
    string s;
    cin >> s;
    rep(i, s.size()){
        if(s.at(i) == '+') ++ans;
        else --ans;
    }
    cout << ans << endl;
}
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
    string s; cin >> s;
    int ans = 999;
    for (int i = 0; i <= (s.size() - 3); i++) {
        int a = (s[i] - '0')* 100 + (s[i+1] - '0') * 10 + (s[i+2] - '0');       
        ans = min(ans, abs(a - 753));
    }
    cout << ans << endl;
} 
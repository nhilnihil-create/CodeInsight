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

int main(){
    ll n;
    cin >> n;
    string ans = "No";
    rep(i, n / 4 + 1){
        rep(j, n / 7 + 1){
            if(i * 4 + j * 7 == n) ans = "Yes";
        }
    }
    cout << ans << endl;
}
   
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <map>
#define ll long long
using namespace std;
#include<bits/stdc++.h>
using namespace std;

int main(void){
    ll n;
    ll inf = 1e9+7;
    cin >> n;
    string s;
    cin >> s;
    vector<ll> check(26, 0);
    for(ll i = 0; i < s.length(); i++){
        ll array = s[i]-97;
        check[array]++;
    }
    ll ans = 1;
    for(ll i = 0; i < 26; i++){
        ans = ans * (check[i]+1)%inf;
        ans %= inf;
    }
    cout << ans-1 << endl;
    return 0;
}

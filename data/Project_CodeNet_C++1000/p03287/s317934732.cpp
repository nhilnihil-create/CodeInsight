#include <bitset>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <iomanip>
#include <stack>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <stdio.h>
#include <math.h>

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef pair<int, int> pii;


#define rep(i, n) for(int i=0; i<(n); ++i)
#define repp(i, a, b) for(int i = (a); i <= (b); i++)
#define repm(i, a, b) for(int i = (a); i >= (b); i--)

#define all(v) v.begin(), v.end()
//sort( all(v) )　などと使える

int n;
ll m;
vector<ll> a;
vector<ll> s;
map<ll, ll> mod_map;

int main(){
    cin >> n >> m;

    a.resize(n);
    rep(i, n){

        int a_i; cin >> a_i;
        a[i] = a_i % m;

    }
    
    s.resize(n+1);

    s[0] = 0; mod_map[s[0]]++;
    rep(i, n){

        s[i+1] = (s[i] + a[i]);
        mod_map[ s[i+1] % m ]++;

    }


   
    ll ans = 0;
    
    for(auto k: mod_map){
        ans += k.second * (k.second-1) / 2;
    }

    cout << ans << endl;
}
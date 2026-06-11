#include <bits/stdc++.h>
#include <string>
#include <vector>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

//ABC 082 c.cpp
int main() {
    int n;
    cin >> n;
    map<int,int> mp;
    rep(i,n){
        int j;cin >> j;
        mp[j]++;
    }
    
    int ans = 0;
    for(auto v : mp){
        if(v.second >= v.first) ans += v.second-v.first;
        else ans += v.second;
    }

    cout << ans << endl;
}
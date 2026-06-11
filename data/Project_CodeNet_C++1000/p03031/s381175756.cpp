#include <cstdio>
#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#define rep(i,n) for (int i=0;i<n;i++)
using ll = long long;
using namespace std;

void solve(){

}
int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<vector<int>> a(m,vector<int>());
    vector<int> b(m);
    rep(i,m){
        int k;
        cin >> k;
        rep(j,k){
            int q;
            cin >> q;
            a[i].push_back(q);
        }
    }
    rep(i,m){
        cin >> b[i];
    }
    ll ans=0;
    for(int bit=0;bit<(1<<n);bit++){
        bool w = true;
        rep(i,m){
            int sum = 0;
            for(int v:a[i]){
                if((1<<(v-1)) & bit){
                    sum++;
                }
            }
            if(sum%2!=b[i]){
                w = false;
            }
        }
        if(w){
            ans++;
        }
    }

    cout << ans;

    return 0;
}
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
    vector<int> a(m);
    rep(i,m) cin >> a[i];
    if(n>=m) cout << 0 << endl; 
    else{
        sort(a.begin(),a.end());
        vector<pair<int,int>> b(m-1);
        rep(i,m-1){
            b[i] = make_pair(a[i+1] - a[i], i);
        }
        sort(b.begin(),b.end(),greater<pair<int,int>>());
        // rep(i,m-1){
        //     cout << b[i].first << " " << b[i].second << endl;
        // }
        vector<int> c(n+1);
        c[0] = -1;
        c[n] = m-1;
        rep(i,n-1){
            c[i+1] = b[i].second;
        }
        sort(c.begin(),c.end());
        // cout << c.size() << endl;
        // rep(i,n+1){
        //     cout << c[i] << endl;
        // }
        ll cnt = 0;
        rep(i,n){
            cnt += a[c[i+1]]-a[c[i]+1];
        }
        cout << cnt << endl;
    }


    return 0;
}
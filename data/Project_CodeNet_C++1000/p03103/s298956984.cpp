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
    vector<pair<ll,ll>> a(n);
    rep(i,n){
        cin >> a[i].first >> a[i].second;
    }
    // rep(i,n){
    //     cout  << a[i].first << a[i].second;
    // }
    sort(a.begin(),a.end());
    ll cost=0;
    ll num=0;
    ll i=0;
    while(num<m){
        if(a[i].second<=m-num){
            cost+=(a[i].first)*a[i].second;
            num+=a[i].second;
        }
        else{
            cost+=(a[i].first)*(m-num);
            num = m;
        }
        i++;
    }
    cout << cost << endl;

    return 0;
}
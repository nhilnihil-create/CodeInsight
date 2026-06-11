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
    int n;
    cin >> n;
    vector<int> a(n+2);
    a[0] = 0;
    a[n+1] = 0;
    rep(i,n) cin >> a[i+1];
    ll ans = 0;
    rep(i,n+1){
        ans += abs(a[i+1]-a[i]);
    }
    for(int i=1;i<n+1;i++){
        cout << ans - abs(a[i]-a[i-1]) - abs(a[i+1]-a[i]) + abs(a[i+1]-a[i-1]) << endl;
    }
    return 0;
}
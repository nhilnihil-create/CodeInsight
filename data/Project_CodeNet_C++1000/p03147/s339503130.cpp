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
    vector<int> h(n);
    int ans = 0;
    int v = 0;
    rep(i,n) cin >> h[i];
    rep(i,n){
        if(h[i]>=v){
            ans += h[i] - v;
            v = h[i];
        }else{
            v = h[i];
        }
    }
    cout << ans << endl;
    return 0;
}
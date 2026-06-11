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
    vector<int> a(n+2);
    rep(i,m){
        int q,w;
        cin >> q >> w;
        a[q]++,a[w+1]--;
    }
    int cnt=0;
    rep(i,n){
        a[i+1]=a[i]+a[i+1];
    }
    rep(i,n+1){
        if(a[i]==m){
            cnt++;
        }
    }
    cout << cnt;

    return 0;
}
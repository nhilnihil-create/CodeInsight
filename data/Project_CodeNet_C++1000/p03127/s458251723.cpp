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
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    bool flag = true;
    rep(i,n-1){
        if(a[i]!=a[i+1]) flag = false;
    }
    if(flag){
        cout << a[0];
        return 0;
    }
    int g = a[0];
    rep(i,n){
        g = __gcd(g,a[i]);
    }
    cout << g << endl;

    return 0;
}
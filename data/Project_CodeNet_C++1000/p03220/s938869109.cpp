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
    int t,e;
    cin >> n >> t >> e;
    double ans = t;
    int res = 0;
    vector<int> a(n);
    rep(i,n){
      cin >> a[i];
    }    
    vector<double> b(n);
    rep(i,n){
        b[i] = (double) t -a[i]*0.006;
    }
    rep(i,n){
        if(abs(e-b[res])>abs(e-b[i])){
            res = i;
        }
    }
    cout << res+1;
    return 0;
}
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
    int n,k;
    cin >> n >> k;
    double ans = 0.0;
    rep(i,n){
        int cnt=0;
        int q=i+1;
        while(q<k){
            cnt++;
            q*=2;
        }
        // cout << cnt << endl;
        double p=1.0;
        rep(i,cnt){
            p*=0.5;
        }
        ans += p;
    }
    cout << setprecision(10) << (double) ans/n << endl;
    return 0;
}
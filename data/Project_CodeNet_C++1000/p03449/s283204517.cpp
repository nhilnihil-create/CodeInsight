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
    cin>> n;
    vector<vector<int>> a(2,vector<int> (n));
    rep(i,2){
        rep(j,n){
            cin>> a[i][j];
        }
    }

    int ans = 0;
    rep(i,n){
        int cnt = 0;
        rep(j,i+1){
            cnt += a[0][j];
        }
        for(int k=i;k<n;k++){
            cnt+=a[1][k];
        }
        ans = max (ans,cnt);
    }

    cout << ans;

    return 0;
}
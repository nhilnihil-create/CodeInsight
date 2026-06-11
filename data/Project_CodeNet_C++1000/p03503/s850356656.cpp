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
    cin>>n;
    vector<vector<int>> a(n,vector<int>(10));
    vector<vector<int>> c(n,vector<int>(11));
    rep(i,n){
        rep(j,10){
            cin >> a[i][j];
        }
    }

    rep(i,n){
        rep(j,11){
            cin >> c[i][j];
        }
    }
    int res = -1000000000;
    for(int i=1;i<(1<<10);i++){
        int ans=0;
        rep(j,n){
            int cnt=0;
            rep(l,10){
                if((i>>l&1)&&a[j][l]){
                    cnt+=1;
                }
            }
            ans+=c[j][cnt];
        }
        if(res<ans){
            res = ans;
        }
    }
    cout << res << endl;

    return 0;
}
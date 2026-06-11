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


// vector<int> dp(10);

void solve(){

}
int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // dp.assign(10,1000);

    int h,w;
    cin >> h >> w;
    int c[10][10];
    rep(i,10){
        rep(j,10){
            cin >> c[i][j];
        }
    }
    
    rep(i,10){
        rep(j,10){
            rep(l,10){
                if(c[j][l]>c[j][i]+c[i][l]){
                    c[j][l]=c[j][i]+c[i][l];
                }
            }
        }
    }

    int ans=0;

    rep(i,h){
        rep(j,w){
            int q;
            cin >> q;
            if(q==-1){
                continue;
            }
            else {
                ans+=c[q][1];
            }
        }
    } 

    cout << ans;

    return 0;
}
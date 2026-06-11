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

    vector<vector<int>> a(3,vector<int>(3)); 

    rep(i,3){
        rep(j,3){
            cin >> a[i][j];
        }
    }
    int d1 = a[0][0]-a[0][1],d2 = a[0][1] - a[0][2];
    rep(i,3){
        if(a[i][0]-a[i][1]==d1&&a[i][1]-a[i][2]==d2){
            continue;
        }
        else{
            cout << "No";
            return 0;
        }
    }

    int g1 = a[0][0] - a[1][0], g2 = a[1][0] - a[2][0];
    rep(i,3){
        if(a[0][i]-a[1][i]==g1&&a[1][i]-a[2][i]==g2){
            continue;
        }
        else{
            cout << "No";
            return 0;
        }
    } 
    cout << "Yes";

    return 0;
}
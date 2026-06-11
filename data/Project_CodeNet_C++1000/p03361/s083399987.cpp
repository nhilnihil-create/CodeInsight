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
    int a,b;
    cin >> a >> b;
    vector<vector<char>> v(a,vector<char>(b));
    rep(i,a){
        rep(j,b){
            cin>>v[i][j];
        }
    }
    bool w;
    int dx[4]={-1,0,1,0};
    int dy[4]={0,-1,0,1};
    rep(i,a){
        rep(j,b){
            if(v[i][j]=='#'){
                w=false;
                rep(k,4){
                    if(i+dy[k]>=0&&i+dy[k]<a&&j+dx[k]>=0&&j+dx[k]<b){
                        if(v[i+dy[k]][j+dx[k]]=='#'){
                            w = true;
                        }
                    }
                }
                if(!w){
                    cout << "No";
                    return 0;
                }
            }
        }
    }

    cout << "Yes";

    return 0;
}

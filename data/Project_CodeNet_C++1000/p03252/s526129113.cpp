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

    string s,t;
    cin >> s >> t;


    vector<vector<int>> v(26,vector<int>(200002));
    vector<vector<int>> g(26,vector<int>(200002));
    for(int i = 0 ; i < 26 ; i++ ){
        v[i][0] = 0; 
        g[i][0] = 0;
    }
    // cout << "Hello" << endl;

    rep(i,t.size()){
        int m = t[i] -'a';
        v[m][0]++;
        v[m][v[m][0]] = i;
    }
    rep(i,s.size()){
        int m = s[i] -'a';
        g[m][0]++;
        g[m][g[m][0]] = i;
    }

    rep(i,26){
        // cout << i << endl;
        if(v[i][0]>1){
            bool flag = false;
            char c;
            rep(j,v[i][0]){
                if(!flag){
                    c = s[v[i][j+1]];
                    flag = true;
                }else{
                    if(c!=s[v[i][j+1]]){
                        cout << "No" << endl;
                        return 0;
                    }
                }
            }
        }
        if(g[i][0]>1){
            bool flag = false;
            char c;
            rep(j,g[i][0]){
                if(!flag){
                    c = t[g[i][j+1]];
                    flag = true;
                }else{
                    if(c!=t[g[i][j+1]]){
                        cout << "No" << endl;
                        return 0;
                    }
                }
            }
        }
        // else if(v[i][0]==1){
        //     char c = s[v[i][1]];
        //     rep(j,g[i][0]){
        //         if(c!=t[g[i][j+1]]){
        //             cout << "No" << endl;
        //             return 0;
        //         }
        //     }
        // }
    }

    cout << "Yes" << endl;

    return 0;
}
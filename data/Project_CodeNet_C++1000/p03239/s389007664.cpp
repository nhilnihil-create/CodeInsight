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
    int n,t;
    cin >> n >> t;
    vector<pair<int,int>> a(n);
    rep(i,n){
        int m,k;
        cin >> m >> k;
        a[i] = {m,k};
    }
    bool frag = false ;
    int q = 1000;
    rep(i,n){
        if(a[i].second<=t){
            frag = true;
            q = min(q,a[i].first);
        }
    }
    if(frag){
        cout << q;
    }
    else{
        cout << "TLE";
    }


    return 0;
}
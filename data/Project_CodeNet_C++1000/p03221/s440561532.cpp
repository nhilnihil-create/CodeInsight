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
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>> a(m);
    rep(i,m){
        cin >> a[i].first >> a[i].second;
    }
    vector<int> w[100001];
    rep(i,m){
        w[a[i].first-1].push_back(a[i].second);
    }
    // vector<map<int,int>> q(n); 
    rep(i,n){
        sort(w[i].begin(),w[i].end());
        // rep(j,w[i].size()){
        //     q[i][w[i][j]] = j+1;
        // }
    }
    rep(i,m){
        printf("%06d%06d\n",a[i].first,int(lower_bound(w[a[i].first-1].begin(),w[a[i].first-1].end(),a[i].second)-w[a[i].first-1].begin()+1));
    }


    return 0;
}
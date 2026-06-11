#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
#include <queue>
#include <math.h>
#include <bitset>
#define INF 100000000000
#define N 200000
#define ll long long
using namespace std;

int main(){
    ll n,m;
    cin>>n>>m;
    
    vector<pair<int,int>> data[n+1];
    
    for (ll i=1; i<=m; i++){
        ll p,q;
        cin>>p>>q;
        data[p].push_back(make_pair(q,i));
    }
    
    int b[m+1];
    int c[m+1];
    
    for (ll i=1; i<=n; i++){
        sort(data[i].begin(),data[i].end());
        for (ll j=0; j<data[i].size(); j++){
            b[data[i][j].second]=i;
            c[data[i][j].second]=j+1;
        }
    }
    
    for (int i=1; i<=m; i++){
        printf("%06d%06d\n", b[i], c[i]);
    }
}
#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
#include <queue>
#include <math.h>
#include <bitset>
#define INF 100000000000
#define N 100001
#define ll long long
using namespace std;

int main(){
    ll n;
    cin>>n;
    
    vector<ll> a[3];
    
    for (int i=0; i<=2; i++){
        for (ll j=0; j<n; j++){
            ll p;
            cin>>p;
            a[i].push_back(p);
        }
    }
    
    for (int i=0; i<=2; i++) sort(a[i].begin(),a[i].end());
    
    ll sum=0;
    for (ll i=0; i<n; i++){
        ll p,q;
        
        if (a[0][0]>=a[1][i]) continue;
        if (a[2][n-1]<=a[1][i]) continue;
        
        auto it1=lower_bound(a[0].begin(),a[0].end(),a[1][i]);
        p=it1-a[0].begin();
        
        auto it2=upper_bound(a[2].begin(),a[2].end(),a[1][i]);
        auto memo=it2-a[2].begin();
        q=a[2].size()-memo;
        
        sum+=p*q;
    }
    
    cout<<sum<<endl;
}
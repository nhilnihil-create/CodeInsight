#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
#include <math.h>
#define ll long long
using namespace std;

int main() {
    int x,y,z,k;
    cin>>x>>y>>z>>k;
    vector<ll> a,b,c;
    ll p;
    for (int i=0; i<x; i++){
        cin>>p;
        a.push_back(p);
    }
    for (int i=0; i<y; i++){
        cin>>p;
        b.push_back(p);
    }
    for (int i=0; i<z; i++){
        cin>>p;
        c.push_back(p);
    }
    
    vector<ll> absum;
    
    for (int i=0; i<x; i++){
        for (int j=0; j<y; j++){
            ll q=a[i]+b[j];
            absum.push_back(q);
        }
    }
    sort(absum.begin(),absum.end());
    reverse(absum.begin(),absum.end());
    
    int q=min(x*y,k);
    
    vector<ll> ans;
    for (int i=0; i<q; i++){
        for (int j=0; j<z; j++){
            ll r=absum[i]+c[j];
            ans.push_back(r);
        }
    }
    sort(ans.begin(),ans.end());
    reverse(ans.begin(),ans.end());
    
    for (int i=0; i<k; i++) cout<<ans[i]<<endl;
}
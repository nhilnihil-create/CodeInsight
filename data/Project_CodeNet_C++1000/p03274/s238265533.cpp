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

ll ab(ll x, ll y){
    if (x<0) x*=-1;
    if (y<0) y*=-1;
    return max(x,y);
}

ll mn(ll x, ll y){
    if (x<0) x*=-1;
    if (y<0) y*=-1;
    return min(x,y);
}

int main(){
    ll n,k;
    cin>>n>>k;
    ll data[n];
    for (ll i=0; i<n; i++){
        cin>>data[i];
    }
    
    vector<ll> num;
    for (ll i=0; i<n-k+1; i++){
        if (data[i]*data[i+k-1]>=0) num.push_back(ab(data[i],data[i+k-1]));
        else{
            ll p=mn(data[i],data[i+k-1])*2+ab(data[i],data[i+k-1]);
            num.push_back(p);
        }
    }
    
    sort(num.begin(),num.end());
    
    cout<<num[0]<<endl;
}
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

ll abs(ll a, ll b){
    if (a>=b) return a-b;
    else return b-a;
}

int main(){
    ll n;
    cin>>n;
    
    ll data[n+1];
    vector<ll> num;
    for (ll i=1; i<=n; i++){
        cin>>data[i];
        num.push_back(data[i]-i);
    }
    
    sort(num.begin(),num.end());
    
    ll sum=0;
    ll v=num.size()/2;
    ll p=num[v];
    
    for (ll i=0; i<n; i++){
        sum+=abs(num[i]-p);
    }
    
    cout<<sum<<endl;
}
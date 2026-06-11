#include <algorithm>
#include <bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;
#define rep(i, n) for (int i = 0; i <(int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
const ll MOD=1000000007;
const ll INF=1000000000000000001;
int main(){
    ll n,m;cin>>n>>m;
    ll a[n],b[n];
    map<ll,ll> mp;
    rep(i,n){
        cin>>a[i]>>b[i];
        mp[a[i]]+=b[i];
    }
    ll sum=0;
    ll pri=0;
    for(auto p:mp){
        if(sum+p.second<=m){
            sum+=p.second;
            pri+=p.first*p.second;
        }
        else {
            pri+=p.first*(m-sum);
            break;
        }
    }
    cout << pri << endl;
}
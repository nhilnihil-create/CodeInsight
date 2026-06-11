#include <cstdio>
#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
#include <cmath>
#include <iomanip>
#include <regex>
#include <bits/stdc++.h>
#include <string>
using namespace std;
using ll = long long;
const ll MOD = 1000000007; 
using plong = pair<ll,ll>;

int main(){
    ll N,K;
    cin>>N>>K;
    ll res=0;
    if(K%2==1){
        ll num = N/K;
        res=num*num*num;
    }else{
        ll num = N/K;
        res += num*num*num;

        num = (N+K/2)/K;
        res += num*num*num;

    }
    cout<<res<<endl;
}

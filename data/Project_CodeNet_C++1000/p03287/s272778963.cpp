#include <cstdio>
#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
#include <cmath>
#include <iomanip>
#include <regex>
#include <queue>
#include <set>
using namespace std;
using ll = long long;
using Lf = long double;
using plong = pair<ll,ll>;


const long MOD = 1000000007;

int main(){
    ll N,M;
    cin>>N>>M;
    vector<ll> A(N);
    ll res=0;
    for(ll i=0;i<N;i++){
        cin>>A[i];
        // if(A[i]%M==0)res++;
    }
    map<ll,ll>mp;
    mp[0]++;
    ll sum = A[0]%M;
    mp[sum]++;
    for(ll i=1;i<N;i++){
        sum = (sum+A[i])%M;
        mp[sum]++;
    }
    
    for(auto p:mp){
        res+=(p.second-1)*(p.second)/2;
        // cout<<p.first<<":"<<p.second<<endl;
    }

    cout<<res<<endl;

}
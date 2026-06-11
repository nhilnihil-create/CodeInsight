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
const int mod = 1000000007;
vector<ll> prime(ll _max){
    vector<ll> res;
    res.push_back(2);
    for(ll i=3;i<=_max;i+=2){
        bool flag = true;
        for(ll j=0;j<res.size();j++){
            if(i%res[j]==0)flag=false;
            if(res[j]*res[j]>i)break;
        }
        if(flag){
            res.push_back(i);    
        }
    }
    return res;

}
int main(){
    ll N;
    cin>>N;
    vector<ll> ps = prime(55555);
    ll cnt=0;
    for(ll i=0;;i++){
        if(ps[i]%5==1){
            cout<<ps[i]<<" ";
            cnt++;
        }
        if(cnt>=N)break;
    }
    cout<<endl;

}
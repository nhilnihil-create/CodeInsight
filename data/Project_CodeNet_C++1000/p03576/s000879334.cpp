#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
#include <queue>
#include <iomanip>
#include <set>
//#include <bits/stdc++.h>

template<typename T> bool chmax(T &a,T b){
    if(a<b){
        a=b;
        return true;
    }
    return false;
}

template<typename T> bool chmin(T &a,T b){
    if(a>b){
        a=b;
        return true;
    }
    return false;
}

using namespace std;
#define ALL(X) X.begin(),X.end()
using ll = long long int;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
const int MOD=1000000007;
//const int MOD=998244353;
const int INTMAX=1001001000;
const ll LLMAX=1010010010010010000;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll N,K;
    cin>>N>>K;
    vll x(N),y(N);
    for(ll i=0;i<N;i++)cin>>x[i]>>y[i];
    
    ll ans=-1;
    for(ll i1=0;i1<N;i1++){
        for(ll i2=0;i2<N;i2++){
            for(ll j1=0;j1<N;j1++){
                for(ll j2=0;j2<N;j2++){
                    ll x1=min(x[i1],x[i2]);
                    ll x2=max(x[i1],x[i2]);
                    ll y1=min(y[j1],y[j2]);
                    ll y2=max(y[j1],y[j2]);
                    ll count=0;
                    for(ll i=0;i<N;i++){
                        if(x1<=x[i] && x[i]<=x2 && y1<=y[i] && y[i]<=y2){
                            count++;
                            if(count==K)break;
                        }
                    }
                    //printf("x:%d,%d,,y:%d,%d,,count:%d\n",x1,x2,y1,y2,count);
                    if(count==K){
                        if(ans==-1)ans=(x2-x1)*(y2-y1);
                        else chmin(ans,(x2-x1)*(y2-y1));
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
    
    return 0;
}

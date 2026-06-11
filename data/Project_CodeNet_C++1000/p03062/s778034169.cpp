#include <bits/stdc++.h>
#define rep(i,n) for(long long i=0; i<n; i++)
#define Rep(i,n) for(long long i=1; i<n; i++)
#define ll long long
#include <math.h>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
#include <set>
#include <vector>


using namespace std;
#define PI acos(-1)
using P =pair<int,int>;

ll f(ll x,ll c,ll d){
    ll res =x;
    res -=x/c;
    res -=x/d;
    res+= x/lcm(c,d);
    return res;
}

int main(){
    ll n;
    cin>>n;
    ll cnt=0;
    ll a;
    vector<ll>v(n);
    rep(i,n){
        cin>>a;
        if(a<0){cnt++;
        v[i]-=a;
        }else v[i]=a;
    }
    sort(v.begin(),v.end());
    
    ll sum=0;
    rep(i,n){
          sum+=v[i];
          }
    if(cnt%2==0){
        cout<<sum<<endl;
        return 0;
    }else{
        sum-=(v[0]*2);
        cout<<sum<<endl;
        return 0;
    }

}

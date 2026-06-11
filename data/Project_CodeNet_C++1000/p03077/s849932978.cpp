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
   vector<ll>v(5);
   rep(i,5)cin>>v[i];
   ll mi=1000000000000000;
   rep(i,5)mi=min(v[i],mi);
   
   if(n%mi==0){
       cout<<5+n/mi-1<<endl;
   }else{
       cout<<5+n/mi<<endl;
   }
}

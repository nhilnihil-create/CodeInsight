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
   ll n,k;
   cin>>n>>k;
   vector<ll>v(n);
   rep(i,n){
       v[i]=i+1;
   }
   double sum=0;
   ll tmp;
   rep(i,n){
       bool ok=1;
       tmp=v[i];
       ll m=0;
       while(ok){
           if(k<=tmp)break;
           m+=1;
           tmp*=2;
       }
       sum+=1.0/(n*pow(2.0,m));
   }
   cout<< fixed << setprecision(13)<< sum<<endl;
}

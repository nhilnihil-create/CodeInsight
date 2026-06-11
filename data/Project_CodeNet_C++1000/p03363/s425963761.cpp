#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;

int main() {
 ll n;
 cin>>n;
 ll a[n];
 ll ans=0;
 rep(i,n){
   cin>>a[i];
}
 ll sum[n+1];
 sum[0]=0;
 map<ll,ll> b;
 b[0]=1;
 rep(i,n){
  sum[i+1]=sum[i]+a[i];
}
 rep(i,n){
    if(b.find(sum[i+1])==b.end()){
      b[sum[i+1]]=1;
    }
    else {
      b[sum[i+1]]++;
    }
}
for(auto i:b){
    if(i.second>=2){
    ans+=(i.second*(i.second-1))/2;
    }
}
cout<<ans<<endl;
}

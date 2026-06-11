#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int main(){
  ll i,j,x,y,z,a[1010],b[1010],c[1010],k;
  cin >> x >> y >> z >> k;
  for(i=0;i<x;i++){
    scanf("%lld",&a[i]);
    a[i]*=-1;
  }
  for(i=0;i<y;i++){
    scanf("%lld",&b[i]);
    b[i]*=-1;
  }
  for(i=0;i<z;i++){
    scanf("%lld",&c[i]);
    c[i]*=-1;
  }
  sort(a,a+x);
  sort(b,b+y);
  sort(c,c+z);
  ll min=-30000000001,max=-2;
  while(abs(min-max)>1){
    ll mid=(min+max)/2;
    ll sum=0;
    for(i=0;i<x;i++){
      for(j=0;j<y;j++){
        if(a[i]+b[j]<=mid){
          sum+=z;
          continue;
        }
        ll mi=-1,ma=z;
        while(abs(mi-ma)>1){
          ll md=(mi+ma)/2;
          if(c[md]<=mid-a[i]-b[j]){
            mi=md;
          }
          else{
            ma=md;
          }
        }
        sum+=mi+1;
      }
    }
    if(sum>=k){
      max=mid;
    }
    else{
      min=mid;
    }
  }
  vector<ll> ans;
  for(i=0;i<x;i++){
    for(j=0;j<y;j++){
      ll mi=-1,ma=z;
      while(abs(mi-ma)>1){
        ll md=(mi+ma)/2;
        if(c[md]<=max-a[i]-b[j]){
          mi=md;
        }
        else{
          ma=md;
        }
      }
      for(int l=0;l<=mi;l++){
        ans.push_back(a[i]+b[j]+c[l]);
      }
    }
  }
  sort(ans.begin(),ans.end());
  for(i=0;i<k;i++){
    cout << ans[i]*(-1) << endl;
  }
}
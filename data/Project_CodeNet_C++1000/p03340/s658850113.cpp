#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  int n; cin>>n;
  vector<ll> num(n);
  for(int i=0;i<n;i++){
    cin>>num[i];
  }
  ll sum=0,base=0,ans=0,count=0,log=0;
  for(int i=0;i<n;i++){
    sum+=num[i]; base^=num[i];
    if(sum==base){
      count++;
      ans+=count;
    }else{
      count++;
      while(sum!=base){
        count--;
        base^=num[log]; sum-=num[log];
        log++;
      }
      ans+=count;
    }
  }
  cout<<ans<<endl;
}   
#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t n,m,ans=0,sum=0;
  cin >> n >> m;
  vector<pair<int64_t,int64_t>> a(n);
  for(int64_t i=0;i<n;i++)cin >> a[i].first >> a[i].second;
  sort(a.begin(),a.end());
  for(int64_t i=0;i<n;i++){
    if(sum+a[i].second>=m){
      ans+=a[i].first*(m-sum);
      break;
    }else{
      sum+=a[i].second;
      ans+=a[i].first*a[i].second;
    }
  }
  cout << ans << endl;
}
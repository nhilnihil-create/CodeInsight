#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  int a[n];
  int b[n];
  int i;
  for(i=0;i<n;i++)cin>>a[i]>>b[i];
  vector<pair<int,int> >p(n);
  for(i=0;i<n;i++)p[i] = make_pair(a[i]+b[i],i);
  sort(p.begin(),p.end(),greater<pair<int,int> >());
  long ans = 0;
  for(i=0;i<n;i++){
    if(i%2==0){
      ans += a[p[i].second];
    }else{
      ans -= b[p[i].second];
    }
  }
  cout<<ans<<endl;
}

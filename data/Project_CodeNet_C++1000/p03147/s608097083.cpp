#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int> h(n);
  for(int i=0;i<n;++i) cin>>h[i];
  int x,count,sum=0;
  int ans=0;
  while(ans<n){
    count=0;
    x=0;
    ans=0;
    for(int i=0;i<n;++i){
      if(x==0 && h[i]>0) ++count;
      x=h[i];
      if(h[i]>0) --h[i];
      else ans++;
    }
    sum+=count;
  }
  cout<<sum<<endl;
}
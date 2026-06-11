#include <bits/stdc++.h>
using namespace std;
#define LOOP(val, times)   for(val = 0; val < (times); val++)
int main(){
  int n,m;
  cin>>n>>m;
  long long ans=0;
  if(m==0){
    for(int i=m+1;i<=n;i++){
    int h=i-m;
    int k=n/i;
    ans+=h*k;
    int aa=n%i;
    if(aa>m){
      ans+=aa-m;
    }
  }
  cout<<ans<<endl;
  }
  else{
    
  for(int i=m+1;i<=n;i++){
    int h=i-m;
    int k=n/i;
    ans+=h*k;
    int aa=n%i;
    if(aa>=m){
      ans+=aa-m+1;
    }
  }
  cout<<ans<<endl;
  }
}

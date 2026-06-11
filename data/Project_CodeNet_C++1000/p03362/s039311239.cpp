#include <bits/stdc++.h>
using namespace std;
bool prime(int a){
  for(int i=2;i*i<=a;i++)if(a%i==0)return 0;
  return 1;
}



signed main(){
  int n;cin>>n;
  int cnt=0;
  for(int i=11;cnt<n;i+=5){
    if(prime(i)){if(cnt)cout<<" ";cout<<i;cnt++;}
  }
  cout<<endl;
}

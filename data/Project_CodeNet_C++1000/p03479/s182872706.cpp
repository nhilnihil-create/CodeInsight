#include<bits/stdc++.h>
using namespace std;

int main(){
  long long X,Y;
  cin>>X>>Y;
  
  long long tmp=X;
  int ans=0;
  while(tmp<=Y){
    ans++;
    tmp*=2;
  }
  
  cout<<ans<<endl;
  return 0;
}
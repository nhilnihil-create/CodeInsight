#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,ans=0,temp;
  cin>>n;
  while(n>0){
    temp=n%10;
    if(temp==2){
      ans++;
    }
    n=n/10;
  }
  cout<<ans<<endl;
  return 0;
}
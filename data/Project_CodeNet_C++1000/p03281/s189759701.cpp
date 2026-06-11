#include<iostream>
#include<algorithm>
using namespace std;
int main(void)
{ 
  int n,ans;
  cin>>n;
  ans=0;
  if(n>=105)ans++;
  if(n>=165)ans++;
  if(n>=195)ans++;
  if(n>=135){ans++;}
  if(n>=189){ans++;}
  cout<<ans;
  
}
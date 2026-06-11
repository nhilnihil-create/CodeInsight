#include<iostream>
#include<algorithm>

using namespace std;

int main(void)
{
  int a,b,c; cin>>a>>b>>c;
  int r=max({a,b,c})-min({a,b,c});
  
  cout<<r<<endl;
  return 0;
}
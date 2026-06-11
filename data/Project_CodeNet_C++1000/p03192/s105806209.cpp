#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<string>
#include<cstring>
#include<cstdlib>
using namespace std;
int a,ans;
int main()
{
  cin>>a;
  if(a/1000==2)ans++;
  if(a%100/10==2)ans++;
  if(a%1000/100==2)ans++;
  if(a%10==2)ans++;
  cout<<ans<<endl;
  return 0;
}

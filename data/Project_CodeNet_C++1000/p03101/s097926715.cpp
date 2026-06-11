#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

namespace ans
{
  int val=0;
}

int main()
{
  int h,w,H,W;
  cin>>H>>W>>h>>w;
  int tot=H*W;
  int a1=h*W;
  int a2=(H-h)*w;
  //cout<<a1<<endl;
  //cout<<a2<<endl;
  ans::val=tot-a1-a2;
  cout<<ans::val<<endl;
  
  return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main()
{
  int r,d,x1,sum=0;
  cin>>r>>d>>x1;
  for(int i = 1;i<=10;i++){
    sum=(r*x1)-d;
    cout<<sum<<endl;
    x1 = sum;
  }
} 
#include<bits/stdc++.h>
using namespace std;
signed  main()
{
  long long a,b,c=-1;
  cin>>a>>b;
  for(int i=2;i<=1000000;i++){
    if(a*i%b!=0&&c==-1) c=a*i;
  }
  cout<<c<<"\n";
}

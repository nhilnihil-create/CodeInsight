#include <bits/stdc++.h>
using namespace std;
 
int main()
{
 
  int a,b;
  cin>>a>>b;
  string x;
  cin>>x;
 
  int c1=0,c2=0,c3=0;
  bool ck=true;
  for(int i=0;i<x.length();i++)
  {
 
      if(ck==true)
          if(isdigit(x[i]))
            c1++;
      if(ck==false){
        if(isdigit(x[i]))
            c2++;
      }
      if(x[i]=='-')
      {
        c3++;
        ck=false;
      }
  }
  //cout<<c1<<" "<<c2;
  if(c1==a && c2==b && c3==1)
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;
 
}
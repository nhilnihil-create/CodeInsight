  #include<iostream>
using namespace std;
int main()
{
  int a,b,c;
  cin >>a>>b>>c;
  int flag1=0,flag2=0,flag3=0; 
  if(a==b)
  flag1=1;
  if(a==c)
  flag2=1;
  if(b==c)
  flag3=1;
  if(flag1&&flag2&&flag3)
  cout<<"Yes";
  else
  cout<<"No";
  return 0;
} 
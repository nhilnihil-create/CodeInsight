#include<iostream>
#include<algorithm>
using namespace std;
int main (void)
{
  int a[5],i,k;
  for(i=0;i<5;i++){cin>>a[i];}
  cin>>k;
  for(i=0;i<4;i++)
  {
    for(int j=0;j<5;j++)
    {
      if(abs(a[i]-a[j])>k){cout<<":("<<endl;return 0;}
    }
  }
  cout<<"Yay!"<<endl;
}
 
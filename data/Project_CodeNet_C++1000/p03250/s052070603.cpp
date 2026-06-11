#include<iostream>
#include<algorithm>
using namespace std;
int main (void)
{
 int a,b,c;
  cin>>a>>b>>c;
  cout<<max({a,b,c})*9+a+b+c<<endl;
}
#include <iostream>
using namespace std;
int main()
{
  int a,b,c,d;
  cin>>a>>b>>c>>d;
  if (a>=b && c>=d){
    cout<<b+d;
  }else if (a<=b && c>=d){
    cout<<a+d;
  }else if (a>=b && c<=d){
    cout<<b+c;
  }else if (a<=b && c<=d){
    cout<<a+c;
  }
}
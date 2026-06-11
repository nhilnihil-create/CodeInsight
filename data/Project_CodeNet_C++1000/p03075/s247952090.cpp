#include <iostream> 
using namespace std;
void range(int s,int w,int korg)
{
   if((w-s)<=korg)
     cout<<"Yay!";
  else
    cout<<":(";
}
int main()
{
  int a,b,c,d,e,k;
  cin>>a>>b>>c>>d>>e>>k;
  range(a,e,k);
  return 0;
}

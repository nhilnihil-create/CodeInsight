#include<iostream>
using namespace std;
int main()
{
  int n,a,b,t,i,r,res=0;
  cin >> n >> a >> b;
  for(i=1;i<=n;i++){
    t=i;
    r=0;
    while(t>0){
      r+=t%10;
      t/=10;
    }
    if(r>=a && r<=b)
      res+=i;
  }
  cout << res << endl;
  return 0;
}
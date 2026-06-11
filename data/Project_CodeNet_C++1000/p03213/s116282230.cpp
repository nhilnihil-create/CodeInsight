#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
  int n,x,t,i,np=15,res=0;
  int p[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
  int c[5];
  cin >> n;
  fill(c,c+5,0);
  for(i=0;i<np;i++){
    x=n;
    t=0;
    while(x>0){
      t+=x/p[i];
      x/=p[i];
    }
    if(t>=74)
      c[0]++;
    if(t>=24)
      c[1]++;
    if(t>=14)
      c[2]++;
    if(t>=4)
      c[3]++;
    if(t>=2)
      c[4]++;
  }
  res=c[0]+c[1]*(c[4]-1)+c[2]*(c[3]-1)+c[3]*(c[3]-1)*(c[4]-2)/2;
  cout << res << endl;
  return 0;
}
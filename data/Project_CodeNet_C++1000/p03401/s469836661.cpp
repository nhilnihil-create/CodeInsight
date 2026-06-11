#include<iostream>
#include<cmath>
using namespace std;
int N_MAX = 100000;
int main()
{
  int n,a,b,c=0,s,i,res;
  int t[N_MAX];
  cin >> n;
  cin >> b;
  s=abs(b);
  for(i=1;i<n;i++){
    cin >> a;
    s+=abs(a-b);
    t[i-1]=abs(a-b)+abs(b-c)-abs(a-c);
    c=b;
    b=a;
  }
  a=0;
  s+=abs(a-b);
  t[n-1]=abs(a-b)+abs(b-c)-abs(a-c);
  for(i=0;i<n;i++)
    cout << s-t[i] << endl;
  return 0;
}
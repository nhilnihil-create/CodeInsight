#include <bits/stdc++.h>
using namespace std;
 
int main()
{
  int N;
  cin >>N;
  int S=0;
  int p;
  int n=N;
  for(int i=0;i<8;i++)
  {
  p=n%10;
  n=n/10;
  S=S+p;
  if(n==0)break;
  }
if(N%S==0)cout<<"Yes"<<endl;else cout<<"No"<<endl;

}

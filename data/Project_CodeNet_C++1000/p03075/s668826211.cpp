#include <bits/stdc++.h>
using namespace std;
int main()
{
  int a,b,c,d,e,k,i,j,p[5];
  for(i=0;i<5;i++)cin>>p[i];cin>>k;
  for(i=0;i<4;i++)for(j=i+1;j<5;j++)if(abs(p[j]-p[i])>k){cout<<":(";return 0;}
                     cout<<"Yay!";}
                     

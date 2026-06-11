#include<bits/stdc++.h>
using namespace std;
int i,j,n,m,k,l,b;
double x,c;
char u[3];
int main()
{
  for(cin>>n;i<n;i++){
    cin>>x>>u;
    if(strcmp(u,"BTC")==0)x*=380000;
    c+=x;
  }
  printf("%.5f",c);
}
#include<bits/stdc++.h>
using namespace std;
int main(){long long n,i,m=0,p,k,j;
  string x,y,z;
  cin>>n>>x>>y>>z;
  for(i=0;i<n;i++){
      if(x[i]==y[i]&&y[i]!=z[i]){
          m++;
      }if(z[i]==y[i]&&y[i]!=x[i]){
          m++;
      }if(x[i]==z[i]&&y[i]!=z[i]){
          m++;
      }if(x[i]!=y[i]&&y[i]!=z[i]&&x[i]!=z[i]){
          m+=2;
      }
  }cout<<m;
  return 0;
}

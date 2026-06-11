#include<bits/stdc++.h>
long long inf=100000000000000;
using namespace std;
int main(){
  int a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;
  int i;
  long long ans=inf;
  for(i=0;i<=max(x,y)*2;i+=2){
    int pro=i/2;
    long long kari=max(0,x-pro)*a+max(0,y-pro)*b+i*c;
    ans=min(ans,kari);
  }
  cout << ans;
  return(0);
}
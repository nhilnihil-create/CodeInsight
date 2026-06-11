#include<bits/stdc++.h>
using namespace std;
using ld=long double;
ld n,m,d;
int main(){
  cin>>n>>m>>d;
  ld ans=(2*(n-d)*(m-1))/(n*n);
  if(d==0)
    ans=(m-1)/n;
  cout<<fixed<<setprecision(10)<<ans<<endl;
  return 0;
}
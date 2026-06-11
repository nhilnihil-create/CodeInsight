#include <bits/stdc++.h>
using namespace std;

int main(){
  long double n,m,d; cin>>n>>m>>d;
  if(d==0){
    long double ans=1/n;
    ans*=(m-1);
    cout<<setprecision(14)<<ans<<endl;
  }else{
    long double sum=2*(n-d);
    long double ans=sum/(n*n);
    ans*=(m-1);
    cout<<setprecision(14)<<ans<<endl;
  }
}
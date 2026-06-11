#include<bits/stdc++.h>
using namespace std;
using ll=long long;


int main(){
  ll n,m,d;
  cin >> n >> m >> d;
  double ans;
  if(d==0){
    ans=(1.0)/(double)n;
    ans*=(m-1);
  }else{
    ans=(double)(2.0*(n-d))/(double)(n*n);
    ans*=(m-1);
  }
  printf("%.10lf\n",ans);
  return 0;
}

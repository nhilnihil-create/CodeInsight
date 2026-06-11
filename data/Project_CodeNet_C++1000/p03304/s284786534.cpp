#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<ll,ll>

int main(){
  cout<<setprecision(10)<<fixed;
  double n,m,d;
  cin>>n>>m>>d;
  double p;
  if(d==0) p=1/n;
  else p=2*(n-d)/(n*n);
  p*=m-1;
  cout<<p<<endl;
}
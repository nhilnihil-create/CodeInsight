#include<bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(n); i++)
#define ll long long
using namespace std;

int main() {
  int n,m,d; cin>>n>>m>>d;
  double res=1.0/n;
  if (d!=0) res*=2.0*(n-d)/n;
  res*=(m-1.0);
  cout<<setprecision(10)<<res<<endl;
}

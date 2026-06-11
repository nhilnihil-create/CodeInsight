#include <bits/stdc++.h>
using namespace std;
//型に気を付けよう
//a=0x61=97
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long  ll;
typedef long double  ld;
typedef pair<int,int> pairii;
typedef vector<int> veci;
const double pi=3.1415926535;
const ll  mod=1000000007;
//桁数指定　cout << fixed << setprecision(2)
int main() {
  int n,m,x;
  cin>>n>>m>>x;
  veci p(m);
  rep(i,m)cin>>p[i];
  veci v(n,0);
  rep(j,m){
    v[p[j]]=1;
  }
  int cur=0;
  //left
  for(int k=x;k>0;k--)cur+=v[k];
  int ma=cur;
  cur=0;
  for(int l=x;l<n;l++)cur+=v[l];
  ma=min(cur,ma);
  cout<<ma<<endl;
}
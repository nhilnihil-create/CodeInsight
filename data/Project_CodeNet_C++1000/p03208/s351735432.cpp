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
  int  n,k;
  cin>>n>>k;
  veci v(n);
  rep(i,n)cin>>v[i];
  sort(v.begin(),v.end());
  int mi=INT_MAX;
  rep(j,n+1-k){
    mi=min(v[j+k-1]-v[j],mi);
  }
  cout<<mi<<endl;
}
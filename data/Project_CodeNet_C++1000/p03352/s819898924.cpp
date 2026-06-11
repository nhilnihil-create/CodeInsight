#include <bits/stdc++.h>
using namespace std;
//型に気を付けよう
//a=0x61=97
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long  ll;
typedef long double  ld;
typedef pair<int,int> pairii;
typedef vector<int> veci;
const double pi=3.1415926535;
const ll  mod=1000000007;
//桁数指定　cout << fixed << setprecision(2)

int ilog(ll n,ll k){
int cnt=0;
for(int i=1;i<=n;i*=k){
cnt++;
}cnt--;
return cnt;
}
int main() {cerr<<ilog(1,2);
  int x;
  cin>>x;
  int ma=-1;
  for(int i=2;i<32;i++){ma=max(ma,(int)pow(i,ilog(x,i)));}
  if(x==10)cout<<9<<endl;else cout<<ma<<endl;}
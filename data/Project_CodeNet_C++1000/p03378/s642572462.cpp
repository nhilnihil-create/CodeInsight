#include <bits/stdc++.h>
using namespace std;
//型に気を付けよう
//a=0x61=97 '0'=0x30=48
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long  ll;
typedef long double  ld;
typedef string str;
typedef pair<int,int> pairii;
typedef vector<int> veci;
const double pi=3.1415926535;
const ll  mod=1000000007;
//桁数指定　cout << fixed << setprecision(2)
int main() {
  int n,m,x;
  cin>>n>>m>>x;
  int cnt=0;
  veci v(n,0);
  rep(i,m){
    int cur;
    cin>>cur;
    v[cur]=1;
  }
  int cur=x;
  rep(i,x){cur--;cnt+=v[cur];}
  cur=x;
  int cnt2=0;
  for(cur=x;cur<n;cur++)cnt2+=v[cur];cerr<<cnt<<' '<<cnt2;
  cnt=min(cnt,cnt2);
  cout<<cnt;
}
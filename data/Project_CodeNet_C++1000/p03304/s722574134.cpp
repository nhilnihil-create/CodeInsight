#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lvector vector<ll>
#define lque queue<ll>
#define lpque priority_queue<ll>
#define dlpque priority_queue<ll,lvector,greater<ll>>
#define P pair<ll,ll>
#define ALL(a) (a).begin(),(a).end()
#define rep(i,n) for(ll (i)=0; (i)<(n); ++(i))
#define print(a) cout << (a) << endl

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n,m,d;cin>>n>>m>>d;
  double ans;
  if(d==0) ans=1.0*(m-1)/n;
  else ans=2.0*(m-1)*(n-d)/(n*n);
  printf("%.7f\n",ans);
  return 0;
}

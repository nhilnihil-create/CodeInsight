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

ll n,A,B,C,inf=1e9;
vector<ll> bmb(n);

ll dfs(ll x,ll a,ll b,ll c) {
  if(x==n) {
    if(min({a,b,c})>0) return abs(A-a)+abs(B-b)+abs(C-c)-30;
    else return inf;
  }
  ll ret0=dfs(x+1,a,b,c);
  ll ret1=dfs(x+1,a+bmb[x],b,c)+10;
  ll ret2=dfs(x+1,a,b+bmb[x],c)+10;
  ll ret3=dfs(x+1,a,b,c+bmb[x])+10;
  return min({ret0,ret1,ret2,ret3});
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>n>>A>>B>>C;
  bmb.resize(n);rep(i,n) cin>>bmb[i];
  print(dfs(0,0,0,0));
  return 0;
}
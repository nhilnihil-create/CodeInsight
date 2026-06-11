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
  ll n;cin>>n;
  lvector ER(n,0),WL(n,0);
  string s;cin>>s;
  rep(i,n-1) WL[i+1]+=WL[i]+(s[i]=='W');
  rep(i,n-1) ER[n-1-(i+1)]+=ER[n-1-i]+(s[n-1-i]=='E');
  ll ans=1e9;
  rep(i,n) ans=min(ans,WL[i]+ER[i]);
  print(ans);
  return 0;
}
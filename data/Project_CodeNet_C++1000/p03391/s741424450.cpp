#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(c) (c).rbegin(),(c).rend()
#define mp make_pair
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll inf=1e9+7;
const ll mod=998244353;
int main(){
    ll n;cin>>n;
  ll sum=0;
  ll mi=inf;
  rep(i,n){
    ll a,b;cin>>a>>b;
    if(a>b)mi=min(mi,b);
    sum+=a;
  }
  if(mi==inf)cout<<0<<endl;
  else cout<<sum-mi<<endl;
}
#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())

const ll MAX = 510000;
const ll MOD = 1000000007;


ll gcd(ll a, ll b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}


int main(){
  ll N,M;cin>>N>>M;
  string s,t;cin>>s>>t;

  ll c = gcd(N,M);
  ll ans = N*M/c;
  ll tmp = ans/c;

  for(ll i = 0; i < ans; i += tmp){
    if(s[i/(M/c)] != t[i/(N/c)]){
      cout<<-1<<endl;
      return 0;
    }
  }
  cout<<ans<<endl;
}

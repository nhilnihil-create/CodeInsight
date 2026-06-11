#include <bits/stdc++.h>
using namespace std;
#define rep(i, n)  for(long long i=0;i<(long long)(n);i++)
#define REP(i,k,n) for(long long i=k;i<(long long)(n);i++)
#define all(a) a.begin(),a.end()
#define eb emplace_back
#define pb push_back
#define lb(v,k) (lower_bound(all(v),k)-v.begin())
#define ub(v,k) (upper_bound(all(v),k)-v.begin())
typedef long long ll;
typedef multiset<ll> S;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> PP;
typedef priority_queue<ll> PQ;
typedef priority_queue<ll,vector<ll>,greater<ll>> SPQ;
using vi=vector<ll>;
using vvi=vector<vector<ll>>;
const ll inf=1001001001001001;
const int INF=1001001001;
const int mod=1000000007;
bool chmin(auto &a,auto b){if(a>b){a=b;return true;}return false;}
bool chmax(auto &a,auto b){if(a<b){a=b;return true;}return false;}

int main(){
  int n,c=0;cin>>n;
  vi a,b;
  int m=n+1;
  if(n%2)m--;
  REP(i,1,n){
    REP(j,i+1,n+1){
      if(i+j!=m){
        c++;
        a.pb(i);b.pb(j);
      }
    }
  }
  cout<<c<<endl;
  rep(i,c)
    cout<<a.at(i)<<' '<<b.at(i)<<endl;
}

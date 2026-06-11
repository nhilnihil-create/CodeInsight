#pragma GCC optimize("Ofast")
#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
typedef pair<ll,ll> P;
typedef pair<P,long double> Pi;
typedef pair <long double,int> Pd;
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
const ll inf=(1e18);
const ll mod=1000000007;
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
set<int> mp[200005];
ll dp[200005];
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n;cin>>n;
vector<int> c(n);
for(int i=0;i<n;i++)cin>>c[i];
c.erase(unique(all(c)),c.end());
for(int i=0;i<c.size();i++){
   mp[c[i]].insert(i);
}
dp[0]=1;
for(int i=0;i<c.size();i++){
   auto ite=mp[c[i]].find(i);
 if(ite!=mp[c[i]].begin()){
   ite--;
  (dp[i]+=dp[*ite])%=mod;
  }
  (dp[i+1]+=dp[i])%=mod;
   }
cout<<dp[c.size()]<<endl;
}


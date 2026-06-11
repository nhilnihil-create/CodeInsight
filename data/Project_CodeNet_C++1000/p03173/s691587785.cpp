#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define pb push_back
using ll = long long;
using vin=vector<int>;
using vvin=vector<vin>;
using vll=vector<ll>;
using vvll=vector<vll>;
using vst=vector<string>;
using P = pair<ll,ll>;
const int inf=1e9+7;
const ll INF=9e18;
template <typename T> bool chmin(T &a, const T& b){if(a > b){a = b;return true;}return false;}
template <typename T> bool chmax(T &a, const T& b){if(a < b){a = b;return true;}return false;}
template<class T> inline void Yes(T condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
template<class T> inline void YES(T condition){ if(condition) cout << "YES" << endl; else cout << "NO" << endl; }
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
ll a[430];
ll dp[430][430];
ll sum[430];
bool flag[430][430];

ll cost(ll l,ll r){
  if(flag[l][r])return dp[l][r];
  flag[l][r]=true;
  if(l==r)return dp[l][r]=0;
  ll mn=INF;
  for(int i=l;i<=r-1;i++){
   chmin(mn,cost(l,i)+cost(i+1,r));
  }
  if(l==r-1)mn=0;
  //mn+=a[l]+a[l+1]+...+a[r]
  mn+=sum[r];
  if(l-1>=0)mn-=sum[l-1];
  //cout<<l<<" "<<r<<" "<<mn<<endl;
  return dp[l][r]=mn;
}
int main(){
  int n;
  cin>>n;
  rep(i,0,n)cin>>a[i];
  rep(i,0,n){
   sum[i]=a[i];
    if(i-1>=0)sum[i]+=sum[i-1];
    //cout<<sum[i]<<endl;
  }
  cout<<cost(0,n-1)<<endl;
}
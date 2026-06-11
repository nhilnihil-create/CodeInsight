#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) v.begin(),v.end()
#define len(x) (ll)(x).length()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int INF=1e9;
const int di[] = {-1,0,1,0};
const int dj[] = {0,-1,0,1};

int main() {
  ll n,m;
  cin>>n>>m;
  vector<pair<ll,ll>> a(n);
  rep(i,n) cin>>a[i].first>>a[i].second; //値段　個数
  sort(all(a));
  ll ans=0;
  for(int i=0;m>0;i++){
    if(m-a[i].second<0){
      ans+=m*a[i].first;
      m=0;
    }
    if(m-a[i].second>=0){
      ans+=a[i].second*a[i].first;
      m-=a[i].second;
    }
  }
  cout<<ans<<endl;
}
#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define F first
#define S second

using namespace std;
typedef pair<int,int> P;

const int MOD=1000000007;
int INF=100100100100100;
int a[2010];
signed main(){
  int n,k,q;cin>>n>>k>>q;
  int ans=INF;
  rep(i,n)cin>>a[i];
  rep(ima,n){
    vector<int> res;
    vector<int> v;
    rep(i,n){
      if(a[i]>=a[ima])v.pb(a[i]);
      if(a[i]<a[ima] || i==n-1){
        if(v.size()>=k){
          int m=v.size();
          sort(all(v));
          rep(po,m-k+1){
            res.pb(v[po]);
          }
        }
        v.clear();
      }
    }
    
    if(res.size()>=q){
      sort(all(res));
      ans=min(ans,res[q-1]-res[0]);
    }
  }
        
  cout<<ans<<endl;        
  return 0;
}
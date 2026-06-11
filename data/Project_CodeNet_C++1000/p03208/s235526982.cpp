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

int main(){
  int n,k;
  cin>>n>>k;
  vector<int> h(n);
  rep(i,n) cin>>h[i];
  sort(all(h));
  int ans=INF;
  int cnt;
  for(int i=k-1;i<n;i++){
    cnt=h[i]-h[i-k+1];
    ans=min(ans,cnt);
  }
  cout<<ans<<endl;
}
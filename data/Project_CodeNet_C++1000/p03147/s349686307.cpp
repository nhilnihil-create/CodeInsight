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
  int n;
  cin>>n;
  vector<int> h(n);
  rep(i,n) cin>>h[i];
  int ans=0;
  int mx=0;
  int cnt=0;
  while(true){
    if(cnt==n){
      break;
    }
    cnt=0;
    rep(j,n){
      if(h[j]==0){
        cnt++;
        continue;
      }
      ans++;
      if(h[j]!=0){
        while(h[j]!=0){
          h[j]--;
          j++;
        }
      }
    }
  }
  cout<<ans<<endl;
}
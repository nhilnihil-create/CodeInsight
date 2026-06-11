#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
typedef pair<ll,ll> P;

int main() {
  int n,k;
  cin>>n>>k;
  vector<int>a(n);
  rep(i,n){
    cin>>a.at(i);
  }
  int r=min(n,k);
  int ans=-1001001001;
  rep(i,r+1){
    rep(j,i+1){
      priority_queue<int, vector<int>, greater<int>> q;
      rep(x,j){
        q.push(a[x]);
      }
      rep(y,i-j){
        q.push(a[n-1-y]);
      }
      int p=k-i;
      while(p--){
        if(q.size()&&q.top()<0){
          q.pop();
        }
      }
      int now=0;
      while(!q.empty()){
        now+=q.top();q.pop();
      }
      ans=max(ans,now);
    }
  }
  cout<<ans<<endl;
}
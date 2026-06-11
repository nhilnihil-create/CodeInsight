#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double lld;
ll MOD = (1e9)+7;
//#pragma GCC target ("avx2")
//#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")
inline void fastIO(){
  ios_base::sync_with_stdio(0);cin.tie(0);
}

int main(){
  fastIO();
  ll n,m,val;
  priority_queue<ll,vector<ll>,greater<ll>>q;
  cin>>n>>m;
  for(int i=0;i<n;i++){
    cin>>val;
    q.push(val);
  }
  vector<pair<ll,ll>>cb;
  for(int i=0;i<m;i++){
    ll b,c;
    cin>>b>>c;
    cb.push_back(make_pair(c,b));
  }
  sort(cb.begin(),cb.end());
  for(int i=cb.size()-1;i>=0;i--){
    if(cb[i].first<=q.top()){
      break;
    }else{
      while(cb[i].second>0&&cb[i].first>q.top()){
        cb[i].second--;
        q.pop(),q.push(cb[i].first);
      }
    }
  }
  ll ans=0;
  for(int i=0;i<n;i++){
    ans+=q.top();
    q.pop();
  }
  cout<<ans<<endl;
  return 0;
}

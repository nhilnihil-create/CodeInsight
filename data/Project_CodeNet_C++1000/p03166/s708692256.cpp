 #include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()

vector<vector<ll>> vec;
vector<ll> ans;
void dp(ll i) {
if(vec[i].size()==0) {
ans[i]=0;
  return ;
}
  ll a=0;
  for(ll x:vec[i]) {
   ll b;
    if(ans[x-1]>=0) {
b=ans[x-1];
    }
    else {
      dp(x-1);
      b=ans[x-1];
    }
    a=max(a,b);
  }
  
  ans[i]=a+1;
return ;
}

int main() {
ll N,M;
  cin>>N>>M;
  ans=vector<ll>(N,-1);
  vec=vector<vector<ll>> (N,vector<ll>(0));
  for(ll i=0;i<M;i++) {
ll x,y;
    cin>>x>>y;
    vec[x-1].push_back(y);
  }
  
  for(ll i=0;i<N;i++) {
if(ans[i]>=0) {
continue;
}
    else {
 dp(i);
    }
  }
  
  ll m=0;
  for(ll i=0;i<N;i++) {
m=max(ans[i],m);
  }
  
 cout<<m<<endl;
}
  
  
  
  
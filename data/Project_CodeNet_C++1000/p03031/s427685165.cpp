#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> llP;

ll mod(ll a, ll b){
  ll ret=a%b;
  if(ret<0) ret+=b;
  return ret;
}

ll modpow(ll a,ll b,ll c){
  ll res=1;
  while(b>0){
    if(b&1) res=mod(res*a,c);
    a=mod(a*a,c);
    b>>=1;
  }
  return res;
}

vector<int> p;
vector<vector<int>> memo;
bool cur[10];
int ans,n,m;

void dfs(int a){
  if(a==n){
    bool temp=true;
    for(int i=0;i<m;i++){
      int sum=0;
      for(int j=0;j<(int)memo[i].size();j++){
        if(cur[memo[i][j]]) sum++;
      }
      if(sum%2!=p[i]) temp=false;
    }
    if(temp) ans++;
  }
  else{
    for(int i=0;i<2;i++){
      cur[a]=i;
      dfs(a+1);
    }
  }
}

int main() {
  cin>>n>>m;
  memo.resize(m);
  for(int i=0;i<m;i++){
    int k;
    cin>>k;
    for(int j=0;j<k;j++){
      int s;
      cin>>s;
      s--;
      memo[i].push_back(s);
    }
  }
  p.resize(m);
  for(int i=0;i<m;i++){
    int a;
    cin>>a;
    p[i]=a;
  }
  ans=0;
  dfs(0);
  cout<<ans<<endl;
  return 0;
}

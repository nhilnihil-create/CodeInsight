#include<bits/stdc++.h>
#define ll long long int
#define vec vector<ll>
#define mat vector<vec>

using namespace std;

const ll mod=1000000007;
const ll inf=LONG_LONG_MAX;
ll dx4[4]={1,0,-1,0};
ll dy4[4]={0,-1,0,1};
ll dx8[8]={1,0,-1,1,-1,1,0,-1};
ll dy8[8]={1,1,1,0,0,-1,-1,-1};

string zero(ll a){
  string t=to_string(a);
  while(t.size()<6){
    t='0'+t;
  }
  return t;
}

int main(){

  ll n,m;
  cin >> n >> m;
  ll p[m],y[m];
  mat G;
  for(ll i=0;i<m;i++){
    cin >> p[i] >> y[i];
    G.push_back({y[i],p[i],i});
  }
  sort(G.begin(),G.end());

  ll city[n+1]={};//i番目の県に市がいくつあるか
  vector<string> ans(m);
  for(ll i=0;i<m;i++){
    ll a=city[G[i][1]]+1;
    city[G[i][1]]++;
    string t=zero(G[i][1])+zero(a);
    ans[G[i][2]]=t;
  }

  for(ll i=0;i<m;i++)cout << ans[i] << endl;

}
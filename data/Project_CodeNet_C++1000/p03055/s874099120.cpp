#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
vector<ll> node[200005];
bool used[200005];
P d1(ll pos){
  P res=P(0,pos);
  for(int i=0;i<node[pos].size();i++){
    int to=node[pos][i];
    if(used[to]) continue;
    used[to]=true;
    P dans=d1(to);
    if(dans>res) res=dans;
  }
  res.first++;
  return res;
}
int main(){
  ll n;
  cin>>n;
  for(int i=1;i<n;i++){
    ll s,t;
    cin>>s>>t;
    node[s].push_back(t);
    node[t].push_back(s);
  }
  for(int i=1;i<=n;i++) used[i]=false;
  used[1]=true;
  ll ds=d1(1).second;
  for(int i=1;i<=n;i++) used[i]=false;
  used[ds]=true;
  cout<<((d1(ds).first-2)%3==0?"Second":"First")<<endl;
}

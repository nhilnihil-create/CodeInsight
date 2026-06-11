#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool used[100005]={0};
int tp[100005]={0};
vector<int> node[100005];
void dfs(int pos,int val){
  tp[pos]=val;
  val++;
  val%=2;
  for(int i=0;i<node[pos].size();i++){
    int to=node[pos][i];
    if(!used[to]){
      used[to]=true;
      dfs(to,val);
    }
  }
}
int main(){
  ll n,m;
  cin>>n>>m;
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    node[a].push_back(b);
    node[b].push_back(a);
  }
  used[1]=true;
  dfs(1,1);
  ll t0=0,t1=0;
  for(int i=1;i<=n;i++){
    for(int j=0;j<node[i].size();j++){
      int to=node[i][j];
      if(tp[i]==tp[to]){
        ll ans=n*(n-1)/2;
        ans-=m;
        cout<<ans<<endl;
        return 0;
      }
    }
    if(tp[i]==0) t0++;
    else t1++;
  }
  cout<<t0*t1-m<<endl;
}

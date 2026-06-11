#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PP;
const ll MOD = 1000000007;
ll T[100005]={0};//階層
ll oya[100005]={0};//親
ll mai[100005]={0};//下の葉の数
ll used[100005]={0};//
priority_queue<ll,vector<ll>,greater<ll>>wgt;
vector<ll> V[200005];//隣接リスト
priority_queue<PP>Q;
priority_queue<PP>Q2;
ll ans[100005]={0};
void ki(int x){
  for(int j=0;j<V[x].size();j++){
    int now=V[x][j];
    if(used[now]==0){
      oya[now]=x;
      T[now]=T[x]+1;
      used[now]++;
      ki(now);
    }
  }
}
int main(){
  int n;
  cin>>n;
  for(int i=1;i<n;i++){
    int a,b;
    cin>>a>>b;
    V[a].push_back(b);
    V[b].push_back(a);
  }
  for(int i=1;i<=n;i++){
    ll c;cin>>c;wgt.push(c);
  }
  used[1]=1;
  ki(1);
  for(int i=2;i<=n;i++){
    Q.push(make_pair(T[i],i));
  }
  for(int i=2;i<=n;i++){//その頂点より下の頂点の数
    mai[oya[Q.top().second]]+=(mai[Q.top().second]+1);
    Q.pop();
  }
  for(int i=1;i<=n;i++){
    if(mai[i]==0)Q2.push(make_pair(174417441744,i));
    else Q2.push(make_pair(T[i],i));
  }
  ll sum=0;
  for(int i=1;i<=n-1;i++){
    ll r=wgt.top();wgt.pop();sum+=r;
    ans[Q2.top().second]=r;
    Q2.pop();
  }
  ll f=wgt.top();wgt.pop();
  ans[Q2.top().second]=f;
  Q2.pop();
  cout<<sum<<endl;
  for(int i=1;i<=n;i++){
    cout<<ans[i]<<" ";
  }
  cout<<endl;
}

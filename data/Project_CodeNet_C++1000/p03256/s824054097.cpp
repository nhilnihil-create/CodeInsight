#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int N=2e5+2;
int cnt[N][2];
bool check[N];
vector<int> adj[N];
queue<int> lis;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,i,j,k,l,m;
  string s;
  cin>>n>>m>>s;
  s=" "+s;
  for(i=1;i<=m;i++){
    cin>>j>>k;
    adj[j].push_back(k);
    adj[k].push_back(j);
    cnt[k][(int)(s[j]-'A')]++;
    cnt[j][(int)(s[k]-'A')]++;
  }
  for(i=1;i<=n;i++){
    if(!cnt[i][0]||!cnt[i][1]){
      check[i]=true;
      lis.push(i);
    }
  }
  while(lis.size()){
    l=lis.front();
    lis.pop();
    for(i=0;i<adj[l].size();i++){
      j=adj[l][i];
      cnt[j][(int)(s[l]-'A')]--;
      if(!cnt[j][(int)(s[l]-'A')]&&!check[j]){
        check[j]=true;
        lis.push(j);
      }
    }
  }
  for(i=1;i<=n;i++){
    if(!check[i]){
      cout<<"Yes";
        return 0;
    }
  }
  cout<<"No";
}
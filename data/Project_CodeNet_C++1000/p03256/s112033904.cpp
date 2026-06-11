#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int type[200005]={0};
vector<int> node[200005];
int acnt[200005]={0},bcnt[200005]={0};
bool used[200005];
int main(){
  int n,m;
  cin>>n>>m;
  for(int i=1;i<=n;i++){
    used[i]=false;
    char c;
    cin>>c;
    type[i]=(c=='A'?0:1);
  }
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    node[a].push_back(b);
    node[b].push_back(a);
  }
  for(int i=1;i<=n;i++){
    for(int j=0;j<node[i].size();j++){
      int con=node[i][j];
      if(type[con]==0) acnt[i]++;
      else bcnt[i]++;
    }
  }
  queue<int> que;
  int sz=n;
  for(int i=1;i<=n;i++){
    if((acnt[i]==0||bcnt[i]==0)&&!used[i]) {
      que.push(i);
      used[i]=true;
      sz--;
    }
  }
  while(!que.empty()){
    int pos=que.front();
    que.pop();
    for(int i=0;i<node[pos].size();i++){
      int con=node[pos][i];
      if(type[pos]==0) acnt[con]--;
      else bcnt[con]--;
      if((acnt[con]==0||bcnt[con]==0)&&!used[con]){
        que.push(con);
        used[con]=true;
        sz--;
      }
    }
  }
  cout<<(sz>0?"Yes":"No")<<endl;
}

#include<bits/stdc++.h>
#define F first
#define S second
#define int long long
#define double long double
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> iP;
typedef pair<P,int> Pi;
typedef pair<P,P> PP;
double eps=1e-8;
int mod=1e9+7;
int inf=1LL<<55;

signed main(){
  int n,m;
  string s;
  vector<int> e[200000],v;
  cin>>n>>m>>s;
  for(int i=0,a,b;i<m;i++){
    cin>>a>>b;
    a--,b--;
    e[a].push_back(b);
    e[b].push_back(a);
  }

  queue<int> Q;
  int a[200000]={},b[200000]={},c=n;
  bool used[200000]={};

  for(int i=0;i<n;i++){
    for(int j=0;j<e[i].size();j++){
      if(s[e[i][j]]=='A')a[i]++;
      else b[i]++;
    }
    if(!a[i]||!b[i])Q.push(i),used[i]=1;
  }
  while(!Q.empty()){
    int p=Q.front();
    Q.pop();
    c--;
    for(int i=0;i<e[p].size();i++){
      int np=e[p][i];
      if(used[np])continue;
      if(s[p]=='A')a[np]--;
      else b[np]--;
      if(!a[np]||!b[np])Q.push(np),used[np]=1;
    }
  }
  cout<<(c?"Yes":"No")<<endl;
  return 0;
}

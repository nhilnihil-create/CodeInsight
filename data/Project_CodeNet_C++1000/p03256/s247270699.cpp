#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#define MOD 1000000007
typedef long long ll;
using namespace std;
const int N=2e5+1;

int n,m;
int a[N],b[N];
string s;
vector<int> G[N];
bool no_ab[N];

int main(){
  cin>>n>>m;
  cin>>s;

  for(int i=0;i<m;i++){
    int c,d;
    cin>>c>>d;
    c--;
    d--;
    G[c].push_back(d);
    G[d].push_back(c);
    if(s[c]=='A') a[d]++;
    else b[d]++;
    if(s[d]=='A') a[c]++;
    else b[c]++;
  }

  queue<int> Q;
  for(int i=0;i<n;i++){
    if(a[i]==0||b[i]==0){
      no_ab[i]=1;
      Q.push(i);
    }
  }

  while(!Q.empty()){
    int u=Q.front();
    Q.pop();
    for(int v:G[u]){
      if(!no_ab[v]){
        if(s[u]=='A') a[v]--;
        else b[v]--;
        if(a[v]==0||b[v]==0){
          no_ab[v]=1;
          Q.push(v);
        }
      }
    }
  }

  bool flag=0;
  for(int i=0;i<n;i++){
    if(!no_ab[i]) flag=1;
  }

  if(flag) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;

  return 0;
}

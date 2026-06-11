#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a) for(int i=0;i<(a);i++)
const ll MOD=1000000007;

string y="Yes\n", n="No\n";
int ok[202020];
int ans[450][450];

void solve(int num,int sr,int sc,int x){
  if(sr>=x||sc>=x-1) return;
  ans[sr][sc]=ans[sr+1][sc]=num;
  num++;
  for(int i=sc+1;i<x;i++) ans[sr][i]=num++;
  for(int i=sc+1;i<x;i++) ans[sr+1][i]=num++;
  for(int i=sr+2;i<=x;i++){
    ans[i][sc]=ans[sr][i-1];
    ans[i][sc+1]=ans[sr+1][i-1];
  }
  
  solve(num,sr+2,sc+2,x);
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  for(int i=1;i*(i+1)<=202020;i++){
    ok[i*(i+1)]=i;
  }
  int N; cin>>N;
  if(ok[N*2]==0){
    cout<<n<<endl;
    return 0;
  }
  int x=ok[N*2];
  cout<<y<<x+1<<endl;
  solve(1,0,0,x);
  if(ans[x][x-1]==0||ans[x][x-1]>N) ans[x-1][x-1]=ans[x][x-1]=N;
  rep(i,x+1){
    cout<<x<<" ";
    rep(j,x) cout<<ans[i][j]<<" ";
    cout<<endl;
  }
  return 0;
}

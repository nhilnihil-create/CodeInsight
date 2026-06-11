#include <bits/stdc++.h>
using namespace std;
#define nin(n) int n; cin >> n;
#define kin(k) int k; cin >> k;
int n,a,b,c;
vector<int> l;
int dfs(int depth,int x,int y,int z){
  if(depth==n){
    if(min(min(x,y),z)>0){
      return abs(x-a)+abs(y-b)+abs(z-c)-30;
    }
    else{
      return 10000000;
    }
  }
  else{
    int p=dfs(depth+1,x,y,z);
    int q=dfs(depth+1,x+l[depth],y,z)+10;
    int r=dfs(depth+1,x,y+l[depth],z)+10;
    int s=dfs(depth+1,x,y,z+l[depth])+10;
    return min(p,min(q,min(r,s)));
  }
}

int main() {
  
  cin >> n >> a >> b >> c;
  l=vector<int>(n);
  for(int i=0;i<n;i++){
    cin >> l[i];
  }
  cout << dfs(0,0,0,0);
}
    
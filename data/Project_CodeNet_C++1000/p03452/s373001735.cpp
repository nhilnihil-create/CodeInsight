/*

*/
#include<iostream>
#include<iomanip>
#include<ios>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<string>
#include<algorithm>
#include<utility>
#include<math.h>
#include<cstdlib>
#define rep(i, n) for(int i=0;i<n;i++)
#define repb(i, a, b) for(int i=a;i<b;i++)
#define MAX_N 100000

using namespace std;
typedef pair<int, int> P;
typedef long long int ll;

const int INF = 1<<30;
const ll MOD = ll(1e9+7);

int parent[MAX_N+1];
ll d[MAX_N+1];

int root(int num){
  if(parent[num]==num)return num;
  int p = root(parent[num]);
  d[num] += d[parent[num]];
  return parent[num] = p;
}

bool same(int l, int r){
  return root(l)==root(r);
}

void unite(int l, int r, ll dis){
  dis+=d[l]-d[r];
  l = root(l);
  r = root(r);
  parent[r] = l;
  d[r] = dis;
}

int main(){
  int n, m;cin>>n>>m;
  rep(i, n){parent[i]=i;d[i]=0LL;}
  bool ans=true;
  rep(i, m){
    int l, r;ll dis;cin>>l>>r>>dis;
    l--;r--;
    if(same(l, r)){
      if(dis!=d[r]-d[l]){
        ans=false;
      }
    }else{
      unite(l, r, dis);
    }
  }
  cout<<(ans?"Yes":"No")<<endl;
  // system("read -n 1 -s -p \"Press any key to continue...\"");
}

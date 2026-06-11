#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define m1(x) memset(x,-1,sizeof(x))
const int INF = 1e9 + 1;
const ll MOD = 1e9 + 7;
const double PI = 3.141592653589793;

const int MAX_N = 1001001; //埋め
int par[MAX_N];
int rank_union_find[MAX_N];

void init(int n){
  for(int i = 0; i < n; i++){
    par[i] = i;
    rank_union_find[i] = 0;
  }
}

int find(int x){
  if(par[x] == x) return x;
  else return par[x] = find(par[x]);
}


void unite(int x, int y){
  x = find(x);
  y = find(y);
  if(x == y) return;

  if(rank_union_find[x] < rank_union_find[y]){
    par[x] = y;
  }else{
    par[y] = x;
    if(rank_union_find[x] == rank_union_find[y]) rank_union_find[x]++;
  }
}

bool same(int x, int y){
  return find(x) == find(y);
}

int n, m;

int main(){
  cin >> n >> m;
  init(n);
  rep(i, m){
    int x, y, z;
    x--;y--;
    cin >> x >> y >>z;
    unite(x, y);
  }
  set<int> ans;
  rep(i, n){
    ans.insert(find(i));
  }
  cout << ans.size() <<endl;
}
    


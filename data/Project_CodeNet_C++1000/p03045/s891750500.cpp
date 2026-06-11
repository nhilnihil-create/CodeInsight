#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repo(i, n) for(int i=1; i<=n; i++)
#define INF 1001001001
#define INFll 100100100100100
// debug用
#define PrintVec(x) for (auto elementPrintVec: x) { cout << elementPrintVec << " "; } cout << endl;

using namespace std;
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;
const int mod = 1000000007;

vector<int> to[100005];
vector<int> num(100005);
int cnt=0;

void dfs(int v, int p=-1){
  if(num[v]>0)return;
  if(p==-1){
    cnt++;
  }
  num[v]=cnt;
  for(int nv:to[v]){
    dfs(nv, v);
  }
}

int main(){
  int n, m;
  cin >> n >> m;
  rep(i, m){
    int x, y, z;
    cin >> x >> y >> z;
    x--; y--;
    to[x].push_back(y);
    to[y].push_back(x);
  }
  rep(i, n){
    dfs(i);
  }
  cout << cnt << endl;
  return 0;
}

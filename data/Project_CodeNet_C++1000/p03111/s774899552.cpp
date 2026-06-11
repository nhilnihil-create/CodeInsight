#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repo(i, n) for(int i=1; i<=n; i++)
#define ssort(a) sort(a.begin(), a.end())
#define INF 1001001001
#define INFll 100100100100100
// debug用
#define PrintVec(x) for (auto elementPrintVec: x) { cout << elementPrintVec << " "; } cout << endl;

using namespace std;
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;
const int mod = 1000000007;

int n, a, b, c;
int l[10];

int dfs(int i, int x, int y, int z){
  if(i==n){
    if(x>0 && y>0 && z>0){
      return abs(x-a)+abs(y-b)+abs(z-c);
    } else {
      return INF;
    }
  }
  int output=dfs(i+1, x, y, z);
  int res1=dfs(i+1, x+l[i], y, z);
  int res2=dfs(i+1, x, y+l[i], z);
  int res3=dfs(i+1, x, y, z+l[i]);
  if(x>0){
    res1+=10;
  }
  if(y>0){
    res2+=10;
  }
  if(z>0){
    res3+=10;
  }
  output=min(output, res1);
  output=min(output, res2);
  output=min(output, res3);
  return output;
}

int main(){
  cin >> n >>a >> b >>c;
  rep(i, n){
    cin >> l[i];
  }
  int ans=dfs(0, 0, 0, 0);
  cout << ans << endl;
  return 0;
}

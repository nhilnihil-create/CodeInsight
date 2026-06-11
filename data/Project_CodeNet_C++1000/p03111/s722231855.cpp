#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rng(a) a.begin(),a.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
const int INF = 1001001001;

int n, ans = INF;
int x, y, z;
vector<int> l;
void dfs(int cur, int A, int B, int C, int a, int b, int c) {
  if(cur==n) {  //l1~lnまで全探索
    if(A>=1&&B>=1&&C>=1) {
      int cos = abs(a-x)+abs(b-y)+abs(c-z)+(A+B+C-3)*10;//最初に使う竹の分はMP10はいらない(-30)
      ans = min(ans,cos);
      return;
    }
    else return;
  }

  dfs(cur+1, A, B, C, a, b, c);//l[cur]を使わない
  dfs(cur+1, A+1, B, C, a+l[cur], b, c);//l[cur]をxで使う。
  dfs(cur+1, A, B+1, C, a, b+l[cur], c);//l[cur]をyで使う。
  dfs(cur+1, A, B, C+1, a, b, c+l[cur]);//l[cur]をzで使う。
}

int main() {
  cin >> n >> x >> y >> z;
  l.resize(n);
  rep(i,n) cin >> l[i];
  dfs(0,0,0,0,0,0,0);
  cout << ans << endl;
  return 0;
}
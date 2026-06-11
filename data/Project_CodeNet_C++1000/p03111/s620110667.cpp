#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int N;
vector<vector<int>> cand;
void DFS(vector<int> a) {
  if ((int)a.size() == N) {
    int num[4];
    num[0] = 0;
    num[1] = 0;
    num[2] = 0;
    num[3] = 0;
    for (int i = 0; i < N; i++) {
      num[a[i]]++;
    }
    if (num[1] != 0 && num[2] != 0 && num[3] != 0) {
      cand.push_back(a);
    }
    return ;
  }
  for (int i = 0; i < 4; i++) {
    a.push_back(i);
    DFS(a);
    a.pop_back();
  }
  return ;
}
int main() {
  int A,B,C;
  cin >> N >> A >> B >> C;
  int l[N];
  for (int i = 0; i < N; i++) cin >> l[i];
  vector<int> R(1);
  R[0] = 0;
  DFS(R);
  R[0] = 1;
  DFS(R);
  R[0] = 2;
  DFS(R);
  R[0] = 3;
  DFS(R);
  ll ans = 999999999999;
  for (int i = 0; i < cand.size(); i++) {
    int asum = 0;
    int anum = 0;
    int bsum = 0;
    int bnum = 0;
    int csum = 0;
    int cnum = 0;
    for (int j = 0; j < N; j++) {
      if (cand[i][j] == 1) {
        asum += l[j];
        anum++;
      }
      if (cand[i][j] == 2) {
        bsum += l[j];
        bnum++;
      }
      if (cand[i][j] == 3) {
        csum += l[j];
        cnum++;
      }
    }
    ll res = (anum + bnum + cnum - 3) * 10;
    res += abs(asum - A) + abs(bsum - B) + abs(csum - C);
    ans = min(ans,res);
  }
  cout << ans << endl;
  return 0;
}
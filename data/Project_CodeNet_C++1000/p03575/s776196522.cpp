#include <bits/stdc++.h>
using namespace std;

int N, M;
int a[50];
int b[50];
bool tree[50][50];
bool visited[50];

void dfs (int c) {

  // 訪れたことを記録する
  visited[c] = true;

  for (int i = 0; i < N; i++) {

    // 繋がっていない場合は次へ
    if (!tree[c][i]) {
      continue;
    }

    // すでに訪問済みの場合は次へ
    if (visited[i]) {
      continue;
    }

    // 次の頂点を調べる
    dfs(i);

  }

}

int main() {

  cin >> N >> M;

  for (int i = 0; i < M; i++) {
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
    tree[a[i]][b[i]] = true;
    tree[b[i]][a[i]] = true;
  }

  int ans = 0;

  for (int i = 0; i < M; i++) {
    
    // 頂点を繋がっていないと仮定する
    tree[a[i]][b[i]] = false;
    tree[b[i]][a[i]] = false;

    // 訪問済みチェックをリセットする
    for (int j = 0; j < N; j++) {
      visited[j] = false;
    }

    dfs(0);

    bool flg = false;

    // 全部繋がっている（すべて訪問済み）かをチェックする
    for (int j = 0; j < N; j++) {
      if(visited[j] == false) {
        flg = true;
        break;
      }
    }

    // 繋がっていない点がある場合
    if (flg) {
      ans++;
    }

    // 仮定を戻す
    tree[a[i]][b[i]] = true;
    tree[b[i]][a[i]] = true;

  }

  cout << ans << endl;
  return 0;

}
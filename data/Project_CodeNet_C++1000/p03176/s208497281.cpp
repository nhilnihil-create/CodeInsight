#include<bits/stdc++.h>
using namespace std;

int64_t INF = 0; // 2^31-1

vector<int64_t> value; // ノードの値を持つ配列
int n = 1;           // 葉の数

void update(int64_t i, int64_t x) {
  // i 番目の葉の値を x に変える
  i += n - 1; // i 番目の葉のノード番号[1-index]
  value[i] = x;
  while (i > 0) {
    i = (i - 1) / 2; // ノード i の親ノードの番号に変える
    value[i] = max(value[i * 2 + 1],
                   value[i * 2 + 2]); // 左右の子の min を計算しなおす
  }
}

int64_t query(int a, int b, int k, int l, int r) { //a,b,0,0,n
  // [a, b) の区間に対するクエリについて
  // ノード k （区間 [l, r) 担当）が答える
  if (r <= a || b <= l) return INF; // 区間が被らない場合は INF を返す
  if (a <= l && r <= b)
    return value[k]; // ノード k の担当範囲がクエリ区間 [a, b)
  // に完全に含まれる
  else {
    int64_t c1 = query(a, b, 2 * k + 1, l, (l + r) / 2); // 左の子に値を聞く
    int64_t c2 = query(a, b, 2 * k + 2, (l + r) / 2, r); // 右の子に値を聞く
    return max(c1, c2); // 左右の子の値の min を取る
  }
}


int main(){
  int N;
  cin >> N;
  vector<int> H(N);
  vector<int> A(N);
  for(int i=0; i<N; i++){
    cin >> H[i];
  }
  for(int i=0; i<N; i++){
    cin >> A[i];
  }
  //初期化
  while (n < N) n *= 2; // 葉の数を計算（n以上の最小の2冪数）
  value = vector<int64_t>(2 * n - 1, INF);
  
  vector<int64_t> ans(N,0);
  
  
  for(int i=0; i<N; i++){
    ans[i] = A[i] + query(0,H[i],0,0,n);
    update(H[i]-1,ans[i]);
    /*for(int i=0; i<=2*n-1; i++){
      cout << value[i] << " ";
    }
    cout << endl;
    cout << ans[i] << endl;*/
  }
  
  
  cout << *max_element(ans.begin(),ans.end()) << endl;
}
    
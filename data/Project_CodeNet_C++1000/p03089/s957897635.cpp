#include <iostream>
#include <vector>
#include <stack>

#define rep(i, n) for(int i=0; i<n; i++)

using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> b;
  int tmp;
  rep(i, N){
    cin >> tmp;
    b.push_back(tmp);
  }
  // 入力終了

  stack<int> ans;

  // 問題ではj番目にjを挿入しているので，
  // 数列bの左からj番目がjなら取り除けると考える．
  // 先頭から取り除いていくと，k番目のkがk-1番目のkになって
  // 取り除けなくなるので，末尾から取り除いていく
  
  // 末尾から見ていく
  for(int i=N-1; i>=0; i--){
    for(int j=i; j>=0; j--){
      // j番目がjなら取り除き，
      // 答えのスタックに追加
      if(b[j] == j+1){
	ans.push(b[j]);
	b.erase(b.begin() + j);
	break;
      }
    }
  }

  // スタックに入ってる個数が数列の長さと一致しなければNG
  if(ans.size() != N){
    cout << -1 << endl;
    return 0;
  }
  
  // スタックの上から順に表示
  while(!ans.empty() ){
    cout << ans.top() << endl;
    ans.pop();
  }

  return 0;
}

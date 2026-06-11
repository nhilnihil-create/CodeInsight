#include <iostream>

#define rep(i, n) for(int i=0; i<n; i++)

using namespace std;

int main(){
  string S;
  cin >> S;
  // 入力終了

  int N = S.size();

  // S中に出現した文字を記録
  bool appeared[26] = {false};
  rep(i, N)
    appeared[ S[i]-'a'] = true;

  // 出現していないものがあればそれを尻に引っ付ければヨシ！
  rep(i, 26)
    if(!appeared[i]){
      cout << S << (char)(i+'a') << endl;
      return 0;
    }

  // 全部出現してるとき
  for(int i=N-1; i>=0; i--){
    // 文字列S[i]以降で登場していないものを探す
    for(int j=S[i]-'a'; j<26; j++)
      // 登場していないものがあればS[i]以降をj番目のアルファベットで置き換え
      if(!appeared[j]){
	cout << S.substr(0, i) << (char)(j+'a') << endl;
	return 0;
      }
    // 後ろから使っていないフラグを立てる
    appeared[ S[i] -'a'] = false;
  }

  // 該当なし
  cout << -1 << endl;
  
  return 0;
}

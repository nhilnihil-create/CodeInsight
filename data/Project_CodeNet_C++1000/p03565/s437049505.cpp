#include<bits/stdc++.h>
using ll=long long;
using namespace std;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
  //input
  string S, T;
  cin >> S >> T;
  string ans = "";

  for (int i = 0; i < S.size(); i++) {
    bool check = true;//TをSにいれることができるか否か
    string tmp = S;
    for (int j = 0; j < T.size(); j++) {
      if (i + j >= S.size()) { check = false; break; }//Tをいれるには文字数オーバーならパス
      if (S[i+j] != '?' && S[i+j] != T[j]) { check = false; break; }//？でもなくTの入れたい文字を入れられないならパス
      tmp[i+j] = T[j];//Tの条件クリアなので？にはTの文字を入れる
    }
    if (check) {
      for (int i = 0; i < tmp.size(); i++) {
	//任意の文字でいいならaにするのが辞書順で一番早い
	if (tmp[i] == '?') tmp[i] = 'a';
      }
      if (ans == "") ans = tmp;//とりあえずの解答を
      else chmin(ans, tmp);
    }
  }
  if (ans != "") cout << ans << endl;
  else cout << "UNRESTORABLE" << endl;
      
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define REP(i,a,b) for(int i=(int)(a); i<(int)(b); i++)

using ll = long long;

int main(){
  string S;
  cin >> S;
  int K;cin >> K;

  int not_1_digit=0;
  for(int i=0;i<S.size();i++){
    if(S[i]!='1'){
      not_1_digit=i;
      break;
    }
  }

  string ans;
  if(not_1_digit>=K)ans = "1";
  else ans = S[not_1_digit];
  cout << ans << endl;
}

/*
5000兆日経ったら左から大概の文字は1文字目で構成されそうだが…(1除く)

指定されるK番目の文字がK<1E18で5000兆は1e15
数字が2以上だった場合その桁数は最低でも2^(10^15)以上なので何も問題なかったです

ということで頭から文字を見ていって桁数と1じゃない値とのあれこれやると良さげ
*/
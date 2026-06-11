#include <bits/stdc++.h> //C++の標準ライブラリを一行で一括でインクルードする
#include <math.h> //数学関数と数学定数を利用する
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
template<class T> void chmax(T &a,T b) { if (a<b) a=b;}
template<class T> void chmin(T &a,T b) { if (a>b) a=b;}

int main(){
  string s;
  cin >> s;
  
  bool all_same = true;
  rep(i,s.size()-1){
    if(s[i]!=s[i+1]) all_same = false;
  }
  if(all_same){
    cout << s.size() << endl;
    return 0;
  }
  
  int cnt = s.size() / 2;
  char center = s[cnt];
  bool chk = true;
  while(chk){
    if(s[cnt] != center || s[s.size()-1-cnt] != center || cnt == s.size()-1){
      chk = false;
    }else{
      cnt++;
    }
  }
  cout << cnt << endl;
  
  return 0;
}
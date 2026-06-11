#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<(ll)n;++i)


int main() {
  string s,t;cin >> s >> t;

  ll id = -1;//tに適合するsの部分文字列のうちで一番後ろのものの先頭要素番号
  for(ll i=0;i<=(ll)s.size()-(ll)t.size();++i){
    //sのi番目からの部分文字列がtに適合するかを調べる
    for(ll j=0;j<(ll)t.size();++j){
      if( s.at(i+j) == '?' || s.at(i+j) == t.at(j) ){
        //適合したらその要素番号を控える
        if( j == (ll)t.size() - 1 ) id = i;
      }else{
        //合わなければ先頭要素をずらす
        break;
      }
    }
  }
  //適合する部分文字列がないとき : UNRESTORAβLE
  if( id == -1 ){
    cout << "UNRESTORABLE" << endl;
    return 0;
  }
  
  //あるなら、元の'?'以外の文字と適合部分以外は全て'a'にして出力
  for(ll i=0;i<(ll)s.size();++i){
    if( i == id ){
      cout << t;
      i += t.size()-1;
      continue;
    }
    if( s.at(i) == '?' ) cout << 'a';
    else cout << s.at(i);
  }
  cout << endl;
  return 0;
}
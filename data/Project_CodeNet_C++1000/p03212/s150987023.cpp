#include <iostream>
#include <string>

using namespace std;

int count = 0;
int N;


//文字列sに3，5，7が一回以上現れるかどうか
bool check(string s){
  bool flag3 = false, flag5 = false, flag7 = false;
  for(int i=0; i<s.size(); i++){
    if(s[i] == '3')
      flag3 = true;
    else if(s[i] == '5')
      flag5 = true;
    else
      flag7 = true;
  }
  //現れていない文字があれば，論理積は0になる
  return (flag3 & flag5 & flag7);
}

void solve(string s){
  //受け取った文字が10桁以上なら終了
   //受け取った文字がNより大きくても終了
  int num = atoi(s.c_str() );
  if( s.size()>=10 || N<num )
    return ;
  else{
    //3，5，7が全部あるかチェック
    if(check(s) )
      count++;
  }
  
  string s1 = s, s2 = s, s3 = s;
  //3，5，7を順に追加して木を作っていく
  s1.push_back('3');
  s2.push_back('5');
  s3.push_back('7');
  solve(s1);
  solve(s2);
  solve(s3);
}


int main(){
  cin >> N;
  //入力終わり

  string S = "";
  solve(S);
  cout << count << endl;
  
  return 0;
}

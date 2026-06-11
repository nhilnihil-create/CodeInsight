#include<bits/stdc++.h>
using namespace std;
int main(){
  string S,T;
  cin  >> S >> T ;
  /*部分列の抜き出し
  S = S.substr(2,3) <=2番目の要素から3つ抜き出す
  */
  int i = 0;
  while(i<S.size()){
  if(S == T){
    cout << "Yes" <<endl;
    return 0;
  }
  else{
    S = S.at(S.size()-1) + S.substr(0,S.size()-1);
  }
  i++;
}
  cout << "No" << endl;

}
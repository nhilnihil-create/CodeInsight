#include <iostream>

using namespace std;

int main(){
  string S;
  cin >> S;
  //入力終了


  char k[] = "keyence";
  
  //先頭がkでなければ，末尾がkeyenceになるしかない
  if(S[0] != k[0]){
    if(S.substr(S.size()-7) == k )
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  //末尾がeでなければ，先頭がkeyenceになるしかない                
  else if(S[S.size()-1] != k[6]){
    if(S.substr(0, 7) == k)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  else{
    int l = 0, r = 6;
    //左からkeyenceに一致している範囲を探索
    while(S[l]==k[l])
      l++;
    //右からkeyenceにん一致している範囲を探索
    while(S[r-6+S.size()-1]==k[r])
      r--;
    //lとrが交差していればOK
    if(l > r)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  
  
  return 0;
}

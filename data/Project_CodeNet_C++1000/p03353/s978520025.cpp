#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main(){
  string S;
  int K;
  cin >> S >> K;
  //入力終わり

  //firstを昇順に入れていく
  map<string, int> map;
  
  int size = (int)S.size();
  
  for(int i=0; i<size; i++){
    //Sの範囲から出ないように制御
    for(int j=1; j<=min(size-i, 5); j++){
      map[S.substr(i, j) ]++;
    }
  }

  //小さいほうからK番目の文字列を出力して終了
  int count = 0;
  for(auto m : map){
    if(++count == K){
      cout << m.first << endl;
      break;
    }
  }
  
  return 0;
}

#include <iostream>

using namespace std;

int main(void){
  string S;
  cin >> S;

  int i;
  int C_count = 0, C_place; //Cの数とその場所を格納

  //先頭がAでないならWA
  if(S[0] != 'A'){
    cout << "WA" << endl;
    return 0;
  }

  //Cの数
  for(i=0; i<S.size(); i++)
    if(S[i] == 'C'){
      //先頭から3文字目と末尾から2文字目の間ならOK
      if(2<=i && i<=S.size()-2){
	C_count++;
	C_place = i;
      }
      //それ以外の場所にあればWA
      else{
	cout << "WA" << endl;
	return 0;
      }
    }

  //Cが丁度1個でないならWA
  if(C_count != 1){
    cout << "WA" << endl;
    return 0;
  }

  //全て小文字かどうか調べる
  //先頭は飛ばす
  for(i=1; i<S.size(); i++){
    //Cの場所は見なくてよい
    if(i == C_place)
      continue;
    
    //大文字があれば終了
    if('A'<=S[i] && S[i]<='Z'){
      cout << "WA" << endl;
      return 0;
    }
  }

  //上のテストを抜ければAC
  cout << "AC" << endl;

  return 0;
}

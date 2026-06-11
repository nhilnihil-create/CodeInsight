#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;			//入力値
  int orgN;
  int digitN = 0;	//入力値の桁数
  int TotalN = 0;	//入力値の各桁の和
  int tmp;
  
  cin >> N;
  orgN = N;
  
  //入力値の桁数を計算
  for(int i = 1; (N / i) > 0; i = 10 * i){
    ++digitN;
    tmp = i;
   }
  
  //debug
//  cout << "digitN=" << digitN << endl;    
//  cout << "tmp=" << tmp << endl;   
  
  //1桁の数字ならハーシャッド数確定
  if ( digitN == 1){
    TotalN = N;
    cout << "Yes" << endl;
  }
  else{
    
    //Nの各桁の数字の和を求める
    while(tmp > 0){

      //debug
//      cout << "tmp=" << tmp << endl;

      TotalN = TotalN + (N / tmp);
	  N = N % tmp;
      tmp = tmp / 10;
      
      //debug
//      cout << "TotalN=" << TotalN << endl;
//      cout << "N=" << N << endl;
    }
    
    if ( (orgN % TotalN) == 0){
	    cout << "Yes" << endl;
    }
	else{
	    cout << "No" << endl;      
    }
  }

}

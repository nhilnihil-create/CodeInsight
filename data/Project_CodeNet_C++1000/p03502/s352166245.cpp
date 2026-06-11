#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;			//入力値
  int tmpN;
  int TotalN = 0;	//入力値の各桁の和
  
  cin >> N;
  
  
  //入力値の桁数を計算
  tmpN = N;
  while(tmpN > 0){
    TotalN = TotalN + (tmpN % 10);
    tmpN = tmpN /10;
    
	//debug
//    cout << "TotalN=" << TotalN << endl;
//    cout << "tmpN=" << tmpN << endl;
    
  }

  if ( (N % TotalN) == 0){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;      
  }

}

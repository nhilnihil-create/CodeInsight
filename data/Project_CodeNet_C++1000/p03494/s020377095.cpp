#include <bits/stdc++.h>
using namespace std;
int main(){
  //データの数と割った数を宣言
  int N;
  int n = 0;
  cin >> N;
  
  //データ用のセルを宣言
  vector <int> data (N);
  for (int i = 0; i < N; i++){
    cin >> data.at(i) ;
  }
  
  while(true){
    bool exit_odd =false;
    for (int i =0; i < N; i++){
      if(data.at(i) % 2 != 0){
        exit_odd =true;
      }
    }
    if(exit_odd){
      break;
    }
    
    for (int i =0; i < N; i++){
      data.at(i) /= 2;
    }
    n++;
  }
  cout << n << endl;
  
  

}

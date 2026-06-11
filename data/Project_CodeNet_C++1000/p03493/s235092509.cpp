#include <bits/stdc++.h>
using namespace std;
int main (){
  vector<char> data(3);
  int sum = 0;
  
  //データ入力
  for(int i =0;i < 3; i++ ){
    cin >> data.at(i);
  }
  //カウント機能
  for(int i =0;i < 3; i++ ){
    if(data.at(i) == '1'){
    sum++; 
    }
  }
  
  cout << sum <<endl;
  
  
}

#include <bits/stdc++.h>
using namespace std;

 
int main() {
  // 科目の数Nを受け取る
  int N;
  cin >> N;
  
  vector<int> A(210);
  
  int sousa = 0;
  
  for (int i = 0; i < N ; i++){
  
    cin >> A.at(i);

  }
  
  while (true){
  bool oddExist = false;
    for (int j = 0 ; j < N ; j++){
      if (A.at(j)%2 != 0) {
          oddExist = true;
      }
  }
  
    if(oddExist == true){
      break;
  }
    // 半分にする処理
    for (int k = 0; k < N ; k++) {
        A.at(k) = A.at(k)/2;
    }
    ++sousa;
    // cout << sousa << endl;

  }
  
  cout << sousa << endl;

}
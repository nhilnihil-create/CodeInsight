#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, Q, S_len;
  string S;
  cin >> N >> Q >> S;
  
  S_len = (int)(S.length());
  
  vector<int> ACnum(S_len);
  int num = 0, flag = 0;
  
  for (int i = 0; i < S_len; i++){
    if (S.at(i) == 'A'){
      flag = 1;
    }
    else if (S.at(i) == 'C'){
      if (flag == 1){
        num++;
      }
      flag = 0;
    }
    else{
      flag = 0;
    }
    ACnum.at(i) = num;
  }
  
  /*for (int i = 0; i < S_len; i++){
    cout << ACnum.at(i) << endl;
  }*/
  
  for (int i = 0; i < Q; i++){
    int L, R;
    cin >> L >> R;
    
    cout << ACnum.at(R - 1) - ACnum.at(L - 1) << endl;
  }
  
}
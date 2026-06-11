#include <bits/stdc++.h>
using namespace std;
 
int main(){
  vector<int> A(4);
  string S;
  cin >> S;
  for(int i=0;i<4;i++) A.at(i) = S.at(i) - '0';
  
  for (int tmp = 0; tmp < (1 << 3); tmp++) {
//    cout << tmp << endl;
    int sum = A.at(0);
    for(int j=0;j<3;j++){
      if(tmp & (1 << j)) sum += A.at(j+1);
      else  sum -= A.at(j+1);
    }
    if(sum==7){
      cout << A.at(0);
      for(int j=0;j<3;j++){
        if(tmp & (1 << j)) cout << '+';
        else cout << '-';
        cout << A.at(j+1);
      }
      cout << "=7" << endl;
      return 0;
    }
  }
}
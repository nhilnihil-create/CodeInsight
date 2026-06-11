#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, A;
  int chk;
  
  cin >> N >> A;
  chk = N % 500;
  if(chk == 0){
    cout << "Yes" << endl;
  }else if((A - chk) > 0){
    cout << "Yes" << endl;
  }else {
    cout << "No" << endl;
  }
}
  
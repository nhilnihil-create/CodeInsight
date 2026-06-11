#include <bits/stdc++.h>
using namespace std;

int main() {
  string sN;
  cin >> sN;
  int total = stoi( sN );
  int addition = 0;
  
  //桁数
  int digit_number = sN.size();
  for( int i = 0; i < digit_number; ++i ){
    char cN = sN[i];
    int iN = cN - '0';
    addition += iN;
  }
  
  if( total % addition == 0 ){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}

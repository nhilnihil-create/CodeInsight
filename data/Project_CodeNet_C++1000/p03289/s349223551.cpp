#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  string S;
  cin >> S;

  bool A = false;
  bool C = false;
  int upper_cnt = 0;

  if (S.at(0) == 'A') A = true;
  for (int i = 2; i < S.size() - 1; i++)
  {
    if (S.at(i) == 'C') C = true;
  }
  
  for (int i = 0; i < S.size(); i++)
  {
    if(isupper(S.at(i))) upper_cnt += 1;
  }
  
  if (A && C && upper_cnt == 2){
    cout << "AC" << endl;
  }
  else
  {
    cout << "WA" << endl;
  }
  
}
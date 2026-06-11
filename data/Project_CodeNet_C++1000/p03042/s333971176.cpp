#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  string S;
  cin >> S;

  bool YYMM = false;
  bool MMYY = false;

  string L = {S.at(0), S.at(1)};
  int left = stoi(L);
  string R = {S.at(2), S.at(3)};
  int right = stoi(R);

  if (left >= 1 && left <= 12) MMYY = true;
  if (right >= 1 && right <= 12) YYMM = true;

  if (MMYY & YYMM){
    cout << "AMBIGUOUS" << endl;
  }
  else if (MMYY)
  {
    cout << "MMYY" << endl;
  }
  else if (YYMM)
  {
    cout << "YYMM" << endl;
  }
  else
  {
    cout << "NA" << endl;
  }
  
  
  
}
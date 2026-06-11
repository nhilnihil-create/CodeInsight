#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  string S;
  cin >> S;

  set<char> ACGT;
  ACGT.insert('A');
  ACGT.insert('C');
  ACGT.insert('G');
  ACGT.insert('T');

  int ln = 0;
  int max = 0;
  for (int i = 0; i < S.size(); i++)
  {
    if (ACGT.count(S.at(i))){
      ln += 1;
      if (max < ln) max = ln;
    }
    else
    {
      ln = 0;
    }
    

  }
  
  cout << max << endl;
}
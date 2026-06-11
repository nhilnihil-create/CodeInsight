#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  string S;
  cin >> S;
  int mind = 0;

  for (int i = 0; i < 4; i++){
    if (S.at(i) == '+'){
      mind += 1;
    }
    else
    {
      mind -= 1;
    }
    
  }

  cout << mind << endl;
}
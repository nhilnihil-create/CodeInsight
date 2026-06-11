#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  string S;
  cin >> S;

  int near = 999999;
  int num;
  string str;
  for (int i = 0; i < S.size() - 2; i++)
  {
    str = S.substr(i, 3);
    num = stoi(str);
    if (abs(753 - num) < near){
      near = abs(753 - num);
    }  
  }
  
  cout << near << endl;
}
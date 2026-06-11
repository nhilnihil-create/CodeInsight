#include <bits/stdc++.h>
using namespace std;
int main () {
  string S;
  cin >> S;
  int count = 0, flag = 1, front = 0, back = S.size() -1;
  while(front <= back && flag == 1){
    if(S.at(front) == S.at(back)){
	  front++;
      back--;
    } else {
      if(S.at(front) == 'x'){
        count++;
        front++;
      } else if (S.at(back) == 'x'){
        count++;
        back--;
      } else {
        flag = 0;
      }
    }
  }
  cout << (flag ? count : -1) << endl;
  return 0;
}
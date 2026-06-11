#include <bits/stdc++.h>
using namespace std;

int main(){
  int tmp = 0, num = 0;
  string s;
  cin >> s;
  for (int i = 0; i < s.size(); i++){
    if (s.at(i) == 'A' || s.at(i) == 'T' || s.at(i) == 'G' || s.at(i) == 'C'){
      tmp++;
    }
    else{
      tmp = 0;
    }
    if(num < tmp) num = tmp;
  }
  cout << num;
}
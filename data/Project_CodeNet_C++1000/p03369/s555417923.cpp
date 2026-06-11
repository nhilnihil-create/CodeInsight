#include <bits/stdc++.h>
using namespace std;

int main(){
  string str;
  cin >> str;
  int price = 700;
  for(int i = 0; i < 3; i++){
    char a = str.at(i);
    if(a == 'o') price += 100;
  }
  cout << price << endl;
}
  
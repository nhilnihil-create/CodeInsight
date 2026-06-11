#include <bits/stdc++.h>
using namespace std;

int main(){
  string str;
  cin >> str;
  int result = 0;
  for (int i = 0; i < 3; i++){
    if (str[i] == '1'){
    result += 1;
    }
  }
  cout << result << endl;
}
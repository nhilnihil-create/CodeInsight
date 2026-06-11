#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string str;
  int a = 0;
  cin >> str;
  for (int i = 0; i < str.size(); i++){
    if (str[i] == '1'){
      a++;
    }
  }
  cout << a << endl;
}
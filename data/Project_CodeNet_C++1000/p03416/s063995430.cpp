#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int st,ed;
  int count=0;
  
  string num;
  int len;
  
  cin >> st >> ed;
  
  for (int i = st; i <= ed; i++) {
    num = std::to_string(i);
    len = num.length();

    if(num[0] == num[len-1]){
      if(num[1] == num[len-2]){
        count++;
      }
    }
  }
  
  cout << count << endl;
  return 0;
}
#include <iostream>
#include <string>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  int total=0;
  bool flug = false;
  for(int i = 0;i<26;i++){
    for(int j =0;j<15;j++){
      total = 4*i+7*j;
      if(total == N) flug = true;
    }
  }
  if(flug == true) cout << "Yes" << endl;
  else cout << "No" << endl;
}
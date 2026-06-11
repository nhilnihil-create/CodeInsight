#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
  string S;
  cin >> S;
  
  int N = S.size();
  int cnt1 = 0;
  // 010101...
  for(int i = 0;i < N;i++){
    if(i%2 == 0 && S.at(i) == '1') cnt1++;
    if(i%2 == 1 && S.at(i) == '0') cnt1++;
  }
  int cnt2 = 0;
  // 101010...
  for(int i = 0;i < N;i++){
    if(i%2 == 0 && S.at(i) == '0') cnt2++;
    if(i%2 == 1 && S.at(i) == '1') cnt2++;
  }
  
  cout << min(cnt1, cnt2) << endl;
  
  return 0;
}
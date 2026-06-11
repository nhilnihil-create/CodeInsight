#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  vector<int> abc(3);
  
  cin >> abc.at(0) >> abc.at(1) >> abc.at(2);
  
  sort(abc.begin(), abc.end());
  
  int ans = 0;
  ans += (abc.at(2) - abc.at(1)) / 2;
  ans += (abc.at(2) - abc.at(0)) / 2;
  
  if((abc.at(2) - abc.at(1)) % 2 && (abc.at(2) - abc.at(0)) % 2) ans++;
  else if((abc.at(2) - abc.at(1)) % 2 || (abc.at(2) - abc.at(0)) % 2) ans += 2;
  
  cout << ans << endl;
  
  return 0;
}
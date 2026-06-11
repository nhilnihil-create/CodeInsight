#include <iostream>
#include <vector>
using namespace std;

int main(){
  int s;
  vector<int> cnt(1000001);
  
  cin >> s;
  
  cnt.at(s)++;
  for(int i = 2;;i++){
    if(s%2) s = 3*s + 1;
    else s /= 2;
    
    if(cnt.at(s)++){
      cout << i << endl;
      return 0;
    }
  }
  
  return 0;
}
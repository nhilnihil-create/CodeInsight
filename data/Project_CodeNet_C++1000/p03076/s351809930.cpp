#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  vector<int> times(5);
  for(int i = 0;i < 5;i++) cin >> times.at(i);
  
  vector<int> p = {0, 1, 2, 3, 4};
  int ans = 1000;
  do{
    int sum = 0;
    for(int i = 0;i < 5;i++){
      while(sum % 10 != 0) sum++;
      sum += times.at(p.at(i));
    }
    
    ans = min(ans, sum);
  }while(next_permutation(p.begin(), p.end()));
  
  cout << ans << endl;
  
  return 0;
}
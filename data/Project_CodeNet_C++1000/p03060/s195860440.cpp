#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int N;
  cin >> N;
  
  vector<int> V(N);
  for(int i = 0;i < N;i++) cin >> V.at(i);
  vector<int> C(N);
  for(int i = 0;i < N;i++) cin >> C.at(i);
  
  int ans = 0;
  for(int i = 0;i < N;i++) ans += max(0, V.at(i) - C.at(i));
  
  cout << ans << endl;
  
  return 0;
}
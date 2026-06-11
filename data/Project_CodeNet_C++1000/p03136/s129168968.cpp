#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> L(N);
  for(int i = 0;i < N;i++) cin >> L.at(i);
  
  sort(L.begin(), L.end());
  
  int sum = 0;
  for(int i = 0;i < N - 1;i++) sum += L.at(i);
  
  if(L.at(N-1) < sum) cout << "Yes" << endl;
  else cout << "No" << endl;
  
  return 0;
}
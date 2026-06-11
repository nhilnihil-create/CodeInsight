#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int N, T;
  
  cin >> N >> T;
  
  int min_cost = 1001;
  for(int i = 0;i < N;i++){
    int c, t;
    
    cin >> c >> t;
    if(t <= T) min_cost = min(min_cost, c);
  }
  
  if(min_cost < 1001) cout << min_cost << endl;
  else cout << "TLE" << endl;
  
  return 0;
}
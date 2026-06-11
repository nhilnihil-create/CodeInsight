#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> s(n, 0);
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < 10; ++j){
      int k;
      cin >> k;
      s[i] += k << j;
    }
  }
  vector<vector<int>> b(n, vector<int>(11));    
  for(auto& i : b){
    for(auto& j : i){
      cin >> j;  
    }
  }
  
  int ret = INT_MIN;
  int fin = 1 << 10;
  for(int i = 1; i < fin; ++i){
    int tempret = 0;
    for(int j = 0; j < n; ++j){
      int check = s[j] & i;
      int count = 0;
      while(check != 0){
        if(check & 1){
          ++count;
        }
        check = check >> 1;
      }
      tempret += b[j][count];
    }
    ret = max(ret, tempret);
  }
  cout << ret << endl;
  
  return 0;
}

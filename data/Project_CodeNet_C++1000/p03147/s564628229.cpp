#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  cin >> n;
  vector<int> h(n);
  for(int i = 0; i < n; i++){
    cin >> h[i];
  }
  
  int cnt = 0;
  int i = 0;
  while(i < n){
    if(h[i] == 0){
      i++;
      continue;
    }
    int j = i;
    while(j < n){
      if(h[j] == 0)
        break;
      j++;
    }
    
    for(int k = i; k < j; k++){
      h[k]--;
    }
    
    cnt++;
    
  }
  
  cout << cnt << endl;
  
  return 0;
}
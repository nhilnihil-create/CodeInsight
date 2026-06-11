#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  cin >> n;
  
  if(n == 0){
    cout << 2 << endl;
    return 0;
  } else if(n == 1){
    cout << 1 << endl;
    return 0;
  }

  int64_t l0 = 2;
  int64_t l1 = 1;
  int64_t next = 0;
  for(int i=0; i<n-1; i++){
    next = l1 + l0;
    l0 = l1;
    l1 = next;
    //cout << next << endl;
  }
  cout << next << endl;
  return 0; 
}
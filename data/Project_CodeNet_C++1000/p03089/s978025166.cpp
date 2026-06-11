#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;
  vector<int> b(n);
  for(int i=0; i<n; ++i) cin >> b[i];
  
  stack<int> buf;
  int index = n-1;
  while(b.size() > 0){    
    if(index < 0){
      cout << -1 << endl;
      return 0;
    }
    if(b[index] == index+1){
      buf.push(b[index]);
      b.erase(b.begin() + index);
      index = b.size() - 1;
      continue;
    }
    --index;
  }
  
  for(int i=0; i<n; ++i){
    cout << buf.top() << endl;
    buf.pop();
  }
  
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a, b, k;
  cin >> a >> b >> k;
  
  priority_queue<int, vector<int>, greater<int>> pq;
  for(int i=min(a,b); i>0; i--){
    if(a%i == 0 && b%i == 0){
      pq.push(i);
    }
    if(pq.size()==k){
      break;
    }
  }
  
  cout << pq.top() << endl;
}
  

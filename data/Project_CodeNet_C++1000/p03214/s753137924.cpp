#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int k=0;
  vector<int> a(n),b(n),c(n);
  for(int i=0;i<n;i++){
    cin >> a.at(i);
    k += a.at(i);
  }
  for(int i=0;i<n;i++){
    b.at(i) = max(k - n*a.at(i),n*a.at(i) -k);
    c.at(i) = b.at(i);
  }
  sort(c.begin(),c.end());
  
  for(int i=0;i<n;i++){
    if(b.at(i) == c.at(0)){
    cout << i << endl;
      break;
      
    }
  }
  
  return 0;
}

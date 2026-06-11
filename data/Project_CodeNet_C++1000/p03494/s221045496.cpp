#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, j = 0;
  cin >> n;
  vector<int> a(n);
  int c = 0;
  for(int i = 0; i < n; i++){
    cin >> a.at(i);
  }
  while(1){
    j = 0;
    for(int i = 0; i < n; i++){
      if(a.at(i)%2 == 0){
        a.at(i) /= 2;
        j++;
        if(j == n) c++;
        continue;
      }
      else break;
    }
    if(j != n) break;
    else continue;
  }
  cout << c << endl;
  
}
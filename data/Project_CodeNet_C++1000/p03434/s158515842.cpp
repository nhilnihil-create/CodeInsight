#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<int> a(N);
  for(int i = 0; i < N; i++){
    cin >> a.at(i);
  }
  
  sort(a.begin(),a.end());
  reverse(a.begin(),a.end());
  
  int x = 0;
 for(int k = 0; k < N; k += 2 ){
   x  += a.at(k);
 }
  int y = 0;
    for(int j = 1; j < N; j += 2){
      y += a.at(j);
    }
  cout << x - y << endl;
}
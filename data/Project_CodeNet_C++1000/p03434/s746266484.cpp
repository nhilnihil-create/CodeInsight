#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<int> suuji(N);
   for (int i=0; i<N ;i++) {
     cin >> suuji.at(i) ;
   }
  sort(suuji.begin(),suuji.end());
  reverse(suuji.begin(),suuji.end());
  
  int x = 0;
  for (int j=0; j<N ; j++){
    if (j%2==0){
      x = x + suuji.at(j);
    }
    else {
      x = x - suuji.at(j);
    }
  }
  
  cout << x << endl;
      
}
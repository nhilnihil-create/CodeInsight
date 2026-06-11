#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> Diameter(N);
  for(int i = 0; i < N; i++){
    cin >> Diameter.at(i);
  }
  sort(Diameter.begin(), Diameter.end());
  reverse(Diameter.begin(), Diameter.end());
  int Class = 1;
  for(int a = 0; a < N - 1; a++){
    if(Diameter.at(a) ==  Diameter.at(a + 1)){
      continue;
    }
    else{
      Class++;
    }
  }
  cout << Class << endl;
  
}

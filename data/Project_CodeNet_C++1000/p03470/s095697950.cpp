#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, a=0;
  cin >> N;
  
  vector<int>vec(N);
  
  for(int i=0; i<N; i++){
    cin >> vec.at(i);
  }
  
  sort(vec.begin(),vec.end());
  reverse(vec.begin(),vec.end());
  
  for(int j=0; j<N; j++){
    if(j == 0){
      a++;
      continue;
    } 
    else if(vec.at(j)<vec.at(j-1)){
      a++;
    }
  }
  
  cout << a << endl;
}
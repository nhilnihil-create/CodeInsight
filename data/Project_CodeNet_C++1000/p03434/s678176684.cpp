#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,A=0,B=0;
  cin >> N;
  
  vector<int>vec(N);
  vector<int>vec1(N/2);
  vector<int>vec2(N/2);
  
  for(int i=0; i<N; i++){
    cin >> vec.at(i);
  }
  
  sort(vec.begin(),vec.end());
  reverse(vec.begin(),vec.end());
  
  for(int j=0; j<N; j++){
    if(j%2 == 1){
      continue;
    }
    else{
      A=A+vec.at(j);
    }
  }
  
  for(int k=0; k<N; k++){
    if(k%2 == 0){
      continue;
    }
    else{
      B=B+vec.at(k);
    }
  }
  
  cout << A-B << endl;
}
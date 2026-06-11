#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> vec(N);
  for (int i = 0; i<N; i++){
    cin >> vec.at(i);
  }

 sort(vec.begin(), vec.end());
  reverse(vec.begin(), vec.end());
  
 
 int count = 0;
  for (int i = 0; i<N; i++){
    if(i == N-1){
      count++;
      break;
    }
    if(vec.at(i) == vec.at(i+1)){
    }
    else if(vec.at(i) > vec.at(i+1)){
      count++;
    }
    else{
      break;
    }
  }
  cout << count << endl; 
}
      
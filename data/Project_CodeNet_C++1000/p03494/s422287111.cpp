#include <iostream>
#include <vector>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  for(int i=0; i<N; i++){
    cin >> A.at(i);
  }
  int ans = 0;
  bool exist_even = true;
  while(exist_even){
    for(int i=0; i<N; i++){
      if(A.at(i)%2 != 0){
        exist_even = false;
      }else{
        A.at(i) /= 2;
      }
    }
    if(exist_even){
      ans++;
    }
  }
  cout << ans;
  return 0;
}
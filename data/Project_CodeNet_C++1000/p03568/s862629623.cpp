#include<iostream>
#include<vector>
using namespace std;

int main(){
  int N;
  cin >> N;

  vector<int> A(N);
  for(auto& x: A){
    cin >> x;
  }

  long long ans = 1;
  for(int i = 0; i < N; i++){
    ans *= 3;
  }
  long long ans_comp = 1;
  for(auto x: A){
    if(x % 2 == 0){
      ans_comp *= 2;
    }
  }
  cout << ans - ans_comp << endl;
}


#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int>mochi(N);

  for(int i = 0; i < N; i++){
    int d_i;
    cin >> d_i;

    mochi.at(i) = d_i;
  }

  for(int j = 0; j < N; j++){
    for(int k = j + 1; k < N; k++){
      if(mochi.at(j) == mochi.at(k)){
        mochi.at(k) = 0;
      }

    }
  }

  int sum = 0;
  for(int l = 0; l < N; l++){
    if(mochi.at(l) != 0){
      sum++;
    }
  }

  cout << sum << endl;


}
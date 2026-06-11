#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,D,sum;
  cin >> N >> D >> sum;
  vector<int> A(N);
  for(int i=0;i<N;i++){
    cin >> A.at(i);
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<D;j+=A.at(i)){
      sum++;
    }
  }
  cout << sum << endl;
}
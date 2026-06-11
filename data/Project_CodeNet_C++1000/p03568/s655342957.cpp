#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,seki = 1;
  cin >> N;
  vector<int> A(N);
  for(int i = 0; i < N; i++){
    cin >> A.at(i);
    if (A.at(i) % 2 == 0){
      seki *= 2;
    }
    else {
      seki *= 1;
    }
  }
  cout << pow(3,N) - seki << endl;
}

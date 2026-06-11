#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M;
  
  cin >> N;
  vector<string> blue(N);
  for (int i=0; i<N; i++){
    cin >> blue.at(i);
  }
  
  cin >> M;
  vector<string> red(M);
  for (int i=0; i<M; i++){
    cin >> red.at(i);
  }
  
  int Sum, Answer=0;

  for (int i=0; i<N; i++){
    Sum = 0;
    for (int j=0; j<N; j++){
      if(blue.at(i) == blue.at(j)) Sum++;
    }
    for (int j=0; j<M; j++){
      if(blue.at(i) == red.at(j)) Sum--;
    }
    if(Sum > Answer)
      Answer = Sum;
  }
  cout << Answer << endl;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int A , B;
  cin >> A >> B;
  vector <int> P(N);
  for(int i = 0; i < N; i++){
    cin >> P.at(i);
  }
  int an = 0;
  int sw = 0;
  int er = 0;
  for(int i = 0; i < N; i++){
    if(P.at(i) <= A){
      an++;
    }
    if(P.at(i) > A && P.at(i) <= B){
      sw++;
    }
    if(P.at(i) > B){
      er++;
    }
  }
  cout << min({ an , sw , er}) << endl;
}


#include <bits/stdc++.h>
using namespace std;

int main() {
  int N , M;
  cin >> N;
  int goukei = 0;
  int MAX = 0;
  vector<string> ao(N);
  for (int i = 0; i < N; i++){
    cin >> ao.at(i);
  }
  cin >> M;
  vector<string> aka(M);
  for (int i = 0; i < M; i++){
    cin >> aka.at(i);
  }
  //ここまでok
  for (int i = 0; i < N; i++){
    goukei = 0;
    for(int b = 0; b < N; b++){
      if (ao.at(i) == ao.at(b)){
        goukei++;
      }
    }
    for(int b = 0; b < M; b++){
      if (ao.at(i) == aka.at(b)){
        goukei--;
      }
    }
    if (goukei > MAX){
       MAX = goukei;
    }
  }
  cout << MAX << endl;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int Alice = 0;
  int Bob = 0;
  vector<int> Card(N);
  for(int i = 0; i < N; i++){
    cin >> Card.at(i);
  }
  sort(Card.begin(), Card.end());
  reverse(Card.begin(), Card.end());
  for(int a = 0; a < N; a++){
    if(a % 2 == 0){
      Alice += Card.at(a);
    }
    if(a % 2 != 0){
      Bob += Card.at(a);
    }
  }
  cout << Alice - Bob << endl;
  
  

}

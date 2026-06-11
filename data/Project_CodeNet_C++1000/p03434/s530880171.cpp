#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int>card(N);

  for(int i = 0; i < N; i++){
    int a_i;
    cin >> a_i;

    card.at(i) = a_i;
  }

  sort(card.begin(), card.end());
  reverse(card.begin(), card.end());
  
  int A = 0;
  for(int j = 0; j < N; j += 2){
    A += card.at(j);
  }

  int B = 0;
  for(int k = 1; k < N; k += 2){
    B += card.at(k);
  }

  cout << A - B << endl;




}
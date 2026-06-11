#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> cards(N);
  
  for(int i=0;i<N;i++){
    cin >> cards.at(i);
  }
  
  sort(cards.begin(), cards.end());
  reverse(cards.begin(), cards.end());

  int sum = 0;
  for(int i=0;i<N;i++){
    if(i % 2 == 0){
      sum += cards.at(i);
    }else{
      sum -= cards.at(i);
    }
  }
  cout << sum << endl;
}

#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  vector<int> card(N);
  for(int i = 0; i < N; i++){
    cin >> card[i];
  }
  sort(card.begin(), card.end());
  reverse(card.begin(), card.end());
  
  int alice = 0;
  int bob = 0;
  for (int i = 0; i < N; i++) {
    if(i % 2 == 0){
      alice += card[i];
    }else{
      bob += card[i];
    }
  }
  cout << alice - bob << endl;
  return 0;
}

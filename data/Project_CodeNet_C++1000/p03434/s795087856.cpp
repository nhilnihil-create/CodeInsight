#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; //カードの枚数
  cin >> n;
  vector<int> card(n);
  
  for(int i = 0;i < n;i++){
      cin >> card.at(i);
  }
  
  sort(card.begin(),card.end());
  reverse(card.begin(),card.end());
  
  int alice = 0;
  int bob = 0;
  
  for(int i = 0;i < n;i++){
      if(i % 2 == 0){
          alice += card.at(i);
      }else{
          bob += card.at(i);
      }
  }
  
  cout << alice - bob << endl;
}

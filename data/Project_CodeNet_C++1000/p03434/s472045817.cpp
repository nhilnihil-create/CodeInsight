#include <bits/stdc++.h>
using namespace std;
int main() {
int N , bob=0 , alice=0;

  cin >> N;
  vector <int> card(N);
  for (int i=0; i<N;i++)
  {
   cin >> card.at(i);
  }

  sort(card.begin(),card.end());
      if(N%2==0)
      {
  for(int i;i<N;i++){

    if(i%2 == 0){
    bob+=card.at(i);
    }
      else{
      alice+=card.at(i);
      }
    }
  }
  else {  for(int i;i<N;i++){

    if(i%2 == 0){
      alice+=card.at(i);
      } 
      else {
    bob+=card.at(i);
    }
  }
  }
  cout << alice-bob <<endl;
}
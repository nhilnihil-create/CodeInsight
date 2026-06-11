#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<int> card(N);
  for (int i=0; i<N; i++) cin >> card.at(i);
  
  for (int i=0; i<N-1; i++){
    for (int j=N-1; j>i; j--){
      int tmp;
      if (card.at(j-1)<card.at(j)){
        tmp=card.at(j-1);
        card.at(j-1)=card.at(j);
        card.at(j)=tmp;
      }
    }
  }
  
  int a=0,b=0;
  
  for (int i=0; i<N; i+=2) a+=card.at(i);
  for (int i=1; i<N; i+=2) b+=card.at(i);
  
  cout << a-b << endl;
}
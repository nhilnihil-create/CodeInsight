#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> card(N);
  int i;
  for (i=0;i<N;i++) {
    cin >> card[i];
  }
  sort(card.begin(),card.end(),greater<int>());
  int Alice = 0, Bob = 0;
  int k,j;
    for (k=0;2*k<N;k++) {
      Alice += card[2*k];
    }
    for (j=0;2*j+1<N;j++) {
      Bob += card[2*j+1];
    }
 cout << Alice - Bob <<endl;
}

#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  vector<int> mochi(N);
  for (int i=0 ; i<N ; i++){
  	cin >> mochi.at(i);
  }
  sort(mochi.begin(), mochi.end()); // {1, 2, 2, 5}
  //reverse(card.begin(), card.end()); // {1, 2, 2, 5}
  
  int a = 1;
  for(int i = 1 ; i< N ; i++){
    if (mochi.at(i-1) != mochi.at(i)){
      a++;
    }
  }
  
  cout << a << endl;
}

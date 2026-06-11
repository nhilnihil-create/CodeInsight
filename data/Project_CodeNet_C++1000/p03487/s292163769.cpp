#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  
  vector<int>a(N);
  for (int i = 0; i < N; i++) {
    cin >> a.at(i);
  }
  
  int over = 0;
  vector<int>count(100000,0);
  for (int i = 0; i < N; i++) {
    if (a.at(i) > N){
      over++;
    }
    else {
      count.at(a.at(i)-1)++;
    }
  }
  
  for (int i = 0; i < 100000; i++) {
    if (count.at(i) > i+1){
      over += count.at(i) - i - 1;
    }
    else if (count.at(i) != 0 && count.at(i) < i+1){
      over += count.at(i);
    }
  }
  cout << over << endl;
}
  
  
 

  
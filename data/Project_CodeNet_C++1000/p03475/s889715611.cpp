#include <bits/stdc++.h>
using namespace std;

int main () {
  int N;
  cin >> N;
  
  vector<int>C(N-1);
  vector<int>S(N-1);
  vector<int>F(N-1);
  for (int i = 0; i < N-1; i++) {
    cin >> C.at(i) >> S.at(i) >> F.at(i);
  }
  
  vector<int>time(N-1,0);
  for (int i = 0; i < N-1; i++) {
    for (int j = i; j < N-1; j++) {
      if (time.at(i) < S.at(j)){
        time.at(i) = C.at(j) + S.at(j);
      }
      else {
        if ((time.at(i)-S.at(j)) % F.at(j) == 0){
          time.at(i) += C.at(j);
        }
        else {
          time.at(i) += F.at(j)- ((time.at(i)-S.at(j)) % F.at(j)) + C.at(j);
        }
      }
    }
    cout << time.at(i) << endl;
  }
  
  cout << 0 << endl;
}
      
  
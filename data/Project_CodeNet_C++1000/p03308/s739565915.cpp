#include <bits/stdc++.h>
using namespace std;

int main() {
   
  int N;
  cin >> N;
  vector<int> A(N);
  
  
  for (int i=0; i<N; i++){
	cin >> A.at(i);
  }
    int maximum = A.at(0);
    int minimum = A.at(0);
  for (int i=0; i<N; i++){
   
    if (maximum < A.at(i)) maximum = A.at(i);
    if (A.at(i) < minimum) minimum = A.at(i);
  }
  
  cout << maximum - minimum << endl;

}

#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  int Alice = 0, Bob = 0;
  
  for (int i = 0; i < N; i++)
    cin >> A.at(i);
  
  sort(A.begin(), A.end());
  
  for (int i = N-1; i >= 0; ){
  	Alice += A.at(i);
    if(i-1 >= 0)
  		Bob += A.at(i-1);
    i = i-2;
    }
  cout << Alice - Bob << endl;
}
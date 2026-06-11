#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int>A(N);
  for(int i=0; i<N; i++)cin >> A.at(i);
  
  vector<int>kisuu(N);
  for(int i=0; i<N; i++){
    if(A.at(i)%2==0)kisuu.at(i)=2;
    else kisuu.at(i)=1;
  }
  
  int kaijo = std::pow(3, N);
  int odd=1;
  for(int i=0; i<N; i++)odd*=kisuu.at(i);
  
  cout << kaijo - odd << endl;
}
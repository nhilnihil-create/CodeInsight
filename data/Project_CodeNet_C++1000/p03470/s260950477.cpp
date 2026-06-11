#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  vector<int> D(110);

  for(int i=0; i<N; i++) cin >> D.at(i);

  vector<int> number(110);
  for(int i=0; i <N; i++) {
    number.at(D.at(i))++;
  }
  
  int count =0;
  for(int i =1; i<=100; i++) {
    if(number.at(i)>0) count++;
  }
 
  cout << count  << endl;
}
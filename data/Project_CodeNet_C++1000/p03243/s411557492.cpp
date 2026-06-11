#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  int i = 0;
  while(i*100 +i*10 +i < N){
    i++;
  }
  cout << i*100 +i*10 +i << endl;
}
#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,K;
  cin >> N >> K;
 
  int count;
  if ((N-1) % (K-1) == 0){
    count = (N-1) / (K-1);
  }
  else {
    count = (N-1) / (K-1) + 1;
  }
  cout << count << endl;
}
  
  
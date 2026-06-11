#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  int N = S.size();
  
  int count =0;
  
  for(int i=0; i<N; i++){
    if(S.at(i)=='1'){
      count ++;
    }
  }
  
  cout << min(count, N-count)*2 << endl;
}
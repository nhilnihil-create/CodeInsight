#include <bits/stdc++.h>
using namespace std;

int main(){
  
  string S;
  cin >> S;
  
  int N = (int)S.size();
  int reds = 0;
  int blues = 0;
  for (int i = 0; i < N; i++) {
    if(S[i]=='0') reds++;
    else blues++;
  }
  
  cout << min(reds,blues)*2 << endl;
  
  return 0;
}

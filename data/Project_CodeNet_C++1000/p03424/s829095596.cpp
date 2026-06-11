#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, sum=0;
  cin >> N;
  bool A[4]={false,false,false,false};
  char S[N];
  
  for(int i=0; i<N; i++){
    cin >> S[i];
    if(S[i] == 'P') A[0] = 1;
    else if(S[i] == 'W') A[1] = 1;
    else if(S[i] == 'G') A[2] = 1;
    else if(S[i] == 'Y') A[3] = 1;
  }
  
  sum = A[0]+A[1]+A[2]+A[3];
  
  if(sum == 3) cout << "Three" << endl;
  else cout << "Four" << endl;
  
  return 0;
}

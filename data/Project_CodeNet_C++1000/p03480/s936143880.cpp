#include <bits/stdc++.h>
using namespace std;

int main(void){
  cout << setprecision(15);
  string S;cin >> S;
  int N = S.length(),m=N;
  for(int i = 1; i<N;++i) if(S[i-1]!=S[i]) m = min(m, max(i,N-i));
  cout << m << endl;
  return 0;
}

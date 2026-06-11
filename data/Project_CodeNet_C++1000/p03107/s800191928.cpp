#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  int N,one=0,zero=0;
  cin >> S;
  N = S.size();
  for(int i=0; i<N; i++){
    if(S[i] == '1'){
      one++;
    }
    else{
       zero++;
    }
  }
  cout << N-(abs(one-zero)) << endl;
}

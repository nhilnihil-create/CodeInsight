#include <iostream>
using namespace std;
int main(){
  string S;
  cin >> S;
  int L = S.length();
  int s = L;
  for(int i = 0; i < L; ++i){
    if(i > 0 && S[i] != S[i-1]){
      s = min(s, max(i,L-i));
    }
  }
  cout << s << endl;
  return 0;
}

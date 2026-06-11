#include <iostream>
using namespace std;

int main(){
  string S;
  cin >> S;
  int N = S.length();
  int cnt = 0;
  for(int i = 0; i < N; i++){
    if(S[i] == 'o')cnt++;
  }
  int win = 15 - N + cnt;
  cout << ((win >= 8) ? "YES" : "NO") << endl;
}
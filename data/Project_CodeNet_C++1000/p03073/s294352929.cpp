#include <iostream>

using namespace std;

int haming(string s1, string s2){
  int n=0;
  for (int i = 0; i < s1.size(); i++){
    if (s1[i] != s2[i]) n++;
  }
  return n;
}

int main(){
  string S;
  string S1, S2;
  cin >> S;
  for (int i = 0; i < S.size(); i++){
    S1.append(1, '0' + i%2);
    S2.append(1, '0' + (i+1)%2);
  }

  printf("%d\n", min(haming(S, S1), haming(S, S2)));
  
}

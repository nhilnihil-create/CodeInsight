#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;

int main(){
  int i, j;
  char S[27];
  vector<bool> C(26, false);
  scanf("%s", S);
  for(i = 0; S[i] != '\0'; i++){
    C.at(S[i]-'a') = true;
  }
  if(i != 26){
    for(j = 0; j < 26; j++) if(C.at(j) == false) break;
    S[i] = 'a' + j;
    S[i+1] = '\0';
  }else if(strcmp(S, "zyxwvutsrqponmlkjihgfedcba") == 0){
    cout << -1 << endl;
    return 0;
  }else{
    vector<bool> C2(26, false);
    for(j = 25; j > 0; j--){
      C2.at(S[j]-'a') = true;
      if(S[j-1] < S[j]) break;
    }
    int k;
    for(k = S[j-1] - 'a'; k < 26; k++) if(C2.at(k) == true) break;
    S[j-1] = k + 'a';
    S[j] = '\0';
  }
  cout << S << endl;
  return 0;
}
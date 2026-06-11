#include <iostream>
#include <string>

using namespace std;

int main(){
  string S;
  cin >> S;
  int ans = 0, tmp = 0;
  for (int i = 0; i < (int)S.size(); i++){
    if (S[i] == 'A' || S[i] == 'G' || S[i] == 'C' || S[i] == 'T'){
      tmp++;
    }else{
      if (ans < tmp){
        ans = tmp;
      }
      tmp = 0;
    }
  }
  if (ans < tmp){
    ans = tmp;
  }
  printf("%d\n", ans);
  
}

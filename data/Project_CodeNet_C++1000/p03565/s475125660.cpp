#include<iostream>
#include <string>

using namespace std;

int main(){
  string S,T;
  int flg=-1;
  cin >> S >> T;

  for (int i = (int)S.size() - (int)T.size(); i >= 0; i--){
    for (int j = i, k=0; k < (int)T.size(); j++, k++){
      if(S[j]!=T[k]){
        break;
      }
      if(k==((int)T.size()-1)){
        flg=i;
      }
    }
    if(flg != -1){
      break;
    }
  }

  if(flg==-1){
    for (int i = (int)S.size() - (int)T.size(); i >= 0; i--){
      for (int j = i, k=0; k < (int)T.size(); j++, k++){
        if(S[j]!='?' && S[j]!=T[k]){
          break;
        }
        if(k==((int)T.size()-1)){
          flg=i;
        }
      }
      if(flg != -1){
        break;
      }
    }
  }

  if(flg==-1){
    printf("UNRESTORABLE\n");
  }else{
    for (int i = 0; i < (int)S.size(); i++){
      if(S[i]=='?' && (i < flg || i >= (flg + (int)T.size()))){
        printf("a");
      }else if(i >= flg && i < (flg + (int)T.size())){
        printf("%c",T[i-flg]);
      }else{
        printf("%c",S[i]);
      }
    }
    printf("\n");
  }
}

#include<iostream>
#include<string>
#include <numeric>
#include <algorithm>
#include<queue>
#include<vector>
using namespace std;
typedef pair<int, int> P;
string S, T;

int main(){
  cin >> S >> T;
  int sl = S.length(), tl = T.length();
  
  if(sl < tl){
    cout << "UNRESTORABLE" << endl;
    return 0;
  }
  
  int cnt=0;
  for(int i=0; i<sl; i++){
    if(S[i] == '?') cnt++;
  }
  if(cnt == sl){
    for(int i=0; i<sl-tl+1; i++){
      S.replace(i, 1, "a");
    }
    S.replace(sl-tl, tl, T);
    cout << S << endl;
    return 0;
  }
  
  int index = -1;
  for(int i=0; i<sl-tl+1; i++){
    bool flag=true;
    for(int j=0; j<tl; j++){
      if(S[i+j]!='?' && S[i+j]!=T[j]){
//        cout << j  << endl;
        flag = false;
        break;
      }
    }
    if(flag){
      index = i;
//      cout << i << endl;
    }
  }
  if(index == -1){
    cout << "UNRESTORABLE" << endl;
    return 0;
  }else{
  for(int j=0; j<sl; j++){
    if(index<=j && j<=index+tl-1){
      S.replace(j, tl, T);
        j+=tl-1;
      }
    else if(S[j]=='?'){
      S.replace(j, 1, "a");
    }
  }
  cout << S << endl;
  return 0;
  }
}
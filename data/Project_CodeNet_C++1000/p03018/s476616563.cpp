#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  vector<string> ABC(200000,"0");
  int64_t j=0;
  for(int64_t i=0;i<S.size();i++){
    while(S.at(i)!='A'){
      i++;
      if(i>=S.size()){
        break;
      }
    }
    ABC.at(j)="A";
    while(true){
      if(i>=S.size()-2||S.size()==1){
        i+=2;
        break;
      }else if(S.at(i+1)=='A'){
        ABC.at(j)+="A";
        i++;
      }else if(S.at(i+1)=='B'){
        if(S.at(i+2)=='C'){
          ABC.at(j)+="BC";
          i+=2;
        }else{
          j++;
          break;
        }
      }else{
        j++;
        break;
      }
    }
  }
  j=0;
  int64_t ans=0;
  while(ABC.at(j)!="0"){
    int64_t bc=0;
    for(int i=ABC.at(j).size()-1;i>=0;i--){
      if(ABC.at(j).at(i)=='A'){
        ans+=bc;
      }else{
        bc++;
        i--;
      }
    }
    j++;
  }
  cout << ans << endl;
}
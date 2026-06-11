#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin>>S;
  int ans=0;
  int temp1=0,temp2=0;

  while(1){
    //cout<<temp1<<" "<<temp2<<endl;

    if(temp1==S.length()-1-temp2){
      break;
    }
    if(temp1+1==S.length()-1-temp2){
      if(S.at(temp1)==S.at(S.length()-1-temp2)){
        break;
      }
      if(S.at(temp1)=='x'||S.at(S.length()-1-temp2)=='x'){
        ans++;
        break;
      }
      if(S.at(temp1)!=S.at(S.length()-1-temp2))
      cout<<-1<<endl;
      return 0;
    }

    if(S.at(temp1)==S.at(S.length()-1-temp2)){
      temp1++;
      temp2++;
      continue;  
    }
    if(S.at(temp1)!=S.at(S.length()-1-temp2)){
      if(S.at(temp1)=='x'){
        ans++;
        temp1++;
        continue;
      }
      if(S.at(S.length()-1-temp2)=='x'){
        ans++;
        temp2++;
        continue;
      }      
    }
    cout<<-1<<endl;
    return 0;
  }
  cout<<ans<<endl;
  return 0;
}

    